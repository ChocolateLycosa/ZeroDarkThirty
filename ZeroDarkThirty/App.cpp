#include "pch.h"
#include "App.h"

#include <ppltasks.h>

using namespace ZeroDarkThirty;

using namespace concurrency;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;

// La fonction principale est utilisée uniquement pour initialiser notre classe IFrameworkView.
[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
	auto direct3DApplicationSource = ref new Direct3DApplicationSource();
	CoreApplication::Run(direct3DApplicationSource);
	return 0;
}

IFrameworkView^ Direct3DApplicationSource::CreateView()
{
	return ref new App();
}

App::App() :
	m_windowClosed(false),
	m_windowVisible(true)
{
}

// La première méthode appelée lors de la création de IFrameworkView.
void App::Initialize(CoreApplicationView^ applicationView)
{
	// Inscrivez les gestionnaires d’événements pour le cycle de vie de l’application. Cet exemple inclut Activé, de sorte que nous
	// peut activer CoreWindow et démarrer le rendu sur la fenêtre.
	applicationView->Activated +=
		ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &App::OnActivated);

	CoreApplication::Suspending +=
		ref new EventHandler<SuspendingEventArgs^>(this, &App::OnSuspending);

	CoreApplication::Resuming +=
		ref new EventHandler<Platform::Object^>(this, &App::OnResuming);

	// À ce stade, nous avons accès au périphérique. 
	// Nous pouvons créer les ressources dépendantes du périphérique.
	m_deviceResources = std::make_shared<DX::DeviceResources>();
}

// Appelé lorsque l’objet CoreWindow est créé (ou recréé).
void App::SetWindow(CoreWindow^ window)
{
	window->SizeChanged += 
		ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &App::OnWindowSizeChanged);

	window->VisibilityChanged +=
		ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &App::OnVisibilityChanged);

	window->Closed += 
		ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &App::OnWindowClosed);

	DisplayInformation^ currentDisplayInformation = DisplayInformation::GetForCurrentView();

	currentDisplayInformation->DpiChanged +=
		ref new TypedEventHandler<DisplayInformation^, Object^>(this, &App::OnDpiChanged);

	currentDisplayInformation->OrientationChanged +=
		ref new TypedEventHandler<DisplayInformation^, Object^>(this, &App::OnOrientationChanged);

	DisplayInformation::DisplayContentsInvalidated +=
		ref new TypedEventHandler<DisplayInformation^, Object^>(this, &App::OnDisplayContentsInvalidated);

	m_deviceResources->SetWindow(window);
}

// Initialise les ressources de scène ou charge un état d’application précédemment enregistré.
void App::Load(Platform::String^ entryPoint)
{
	if (m_main == nullptr)
	{
		m_main = std::unique_ptr<ZeroDarkThirtyMain>(new ZeroDarkThirtyMain(m_deviceResources));
	}
}

// Cette méthode est appelée une fois que la fenêtre est active.
void App::Run()
{
	while (!m_windowClosed)
	{
		if (m_windowVisible)
		{
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);

			m_main->Update();

			if (m_main->Render())
			{
				m_deviceResources->Present();
			}
		}
		else
		{
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
		}
	}
}

// Requis pour IFrameworkView.
// Les événements Terminate n'entraînent pas l'appel de Uninitialize. Il sera appelé si votre IFrameworkView
// classe est détruite lorsque l'application est au premier plan.
void App::Uninitialize()
{
}

// Gestionnaires d’événements du cycle de vie de l’application.

void App::OnActivated(CoreApplicationView^ applicationView, IActivatedEventArgs^ args)
{
	// Run() ne démarrera pas tant que CoreWindow n’aura pas été activé.
	CoreWindow::GetForCurrentThread()->Activate();
}

void App::OnSuspending(Platform::Object^ sender, SuspendingEventArgs^ args)
{
	// Enregistrer l'état de l'application de manière asynchrone après avoir demandé un report. Un report en attente
	// indique que l'application exécute des opérations de suspension. Noter
	// qu'un report ne peut pas rester en attente indéfiniment. Après environ cinq secondes,
	// l'application devra se fermer.
	SuspendingDeferral^ deferral = args->SuspendingOperation->GetDeferral();

	create_task([this, deferral]()
	{
        m_deviceResources->Trim();

		// Insérez votre code ici.

		deferral->Complete();
	});
}

void App::OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
	// Restaurer les données ou l’état déchargés lors de la suspension. Par défaut, les données
	// et l'état sont persistants lors de la reprise après la suspension. Noter que cet événement
	// ne se produit pas si l'application a été arrêtée précédemment.

	// Insérez votre code ici.
}

// Gestionnaires d’événements de fenêtre.

void App::OnWindowSizeChanged(CoreWindow^ sender, WindowSizeChangedEventArgs^ args)
{
	m_deviceResources->SetLogicalSize(Size(sender->Bounds.Width, sender->Bounds.Height));
	m_main->CreateWindowSizeDependentResources();
}

void App::OnVisibilityChanged(CoreWindow^ sender, VisibilityChangedEventArgs^ args)
{
	m_windowVisible = args->Visible;
}

void App::OnWindowClosed(CoreWindow^ sender, CoreWindowEventArgs^ args)
{
	m_windowClosed = true;
}

// Gestionnaires d’événements DisplayInformation.

void App::OnDpiChanged(DisplayInformation^ sender, Object^ args)
{
	// Remarque : la valeur de LogicalDpi récupérée ici peut ne pas correspondre à la résolution effective de l'application
	// si elle est mise à l'échelle pour les appareils haute résolution. Une fois la valeur PPP définie sur DeviceResources,
	// vous devez toujours la récupérer à l'aide de la méthode GetDpi.
	// Consultez DeviceResources.cpp pour plus d'informations.
	m_deviceResources->SetDpi(sender->LogicalDpi);
	m_main->CreateWindowSizeDependentResources();
}

void App::OnOrientationChanged(DisplayInformation^ sender, Object^ args)
{
	m_deviceResources->SetCurrentOrientation(sender->CurrentOrientation);
	m_main->CreateWindowSizeDependentResources();
}

void App::OnDisplayContentsInvalidated(DisplayInformation^ sender, Object^ args)
{
	m_deviceResources->ValidateDevice();
}