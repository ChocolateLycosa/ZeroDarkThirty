#include "pch.h"
#include "ZeroDarkThirtyMain.h"
#include "Common\DirectXHelper.h"

using namespace ZeroDarkThirty;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Concurrency;

// Charge et initialise les actifs de l'application lors de son chargement.
ZeroDarkThirtyMain::ZeroDarkThirtyMain(const std::shared_ptr<DX::DeviceResources>& deviceResources) :
	m_deviceResources(deviceResources)
{
	// S'inscrire pour recevoir une notification si le périphérique est perdu ou recréé
	m_deviceResources->RegisterDeviceNotify(this);

	// TODO: remplacez ceci par l'initialisation du contenu de votre application.
	m_sceneRenderer = std::unique_ptr<Sample3DSceneRenderer>(new Sample3DSceneRenderer(m_deviceResources));

	m_fpsTextRenderer = std::unique_ptr<SampleFpsTextRenderer>(new SampleFpsTextRenderer(m_deviceResources));

	// TODO: modifiez les paramètres de minuterie si vous voulez utiliser autre chose que le mode timestep variable par défaut.
	// par exemple, pour une logique de mise à jour timestep fixe de 60 FPS, appelez :
	/*
	m_timer.SetFixedTimeStep(true) ;
	m_timer.SetTargetElapsedSeconds(1.0 / 60) ;
	*/
}

ZeroDarkThirtyMain::~ZeroDarkThirtyMain()
{
	// Annuler l'inscription de la notification de périphériques
	m_deviceResources->RegisterDeviceNotify(nullptr);
}

// Met à jour l'état de l'application lorsque la taille de la fenêtre change (par exemple modification de l'orientation du périphérique)
void ZeroDarkThirtyMain::CreateWindowSizeDependentResources() 
{
	// TODO: remplacez ceci par l'initialisation du contenu de votre application en fonction de la taille.
	m_sceneRenderer->CreateWindowSizeDependentResources();
}

// Met à jour l'état de l'application une fois par frame.
void ZeroDarkThirtyMain::Update() 
{
	// Mettre à jour les objets de scène.
	m_timer.Tick([&]()
	{
		// TODO: remplacez ceci par vos fonctions de mise à jour de contenu d'application.
		m_sceneRenderer->Update(m_timer);
		m_fpsTextRenderer->Update(m_timer);
	});
}

// Affiche le frame actuel en fonction de l'état actuel de l'application.
// Retourne true si le frame a été rendu et est prêt à être affiché.
bool ZeroDarkThirtyMain::Render() 
{
	// N'essayez d'afficher aucun élément avant la première mise à jour.
	if (m_timer.GetFrameCount() == 0)
	{
		return false;
	}

	auto context = m_deviceResources->GetD3DDeviceContext();

	// Réinitialisez la fenêtre d'affichage de manière à ce qu'elle cible la totalité de l'écran.
	auto viewport = m_deviceResources->GetScreenViewport();
	context->RSSetViewports(1, &viewport);

	// Réinitialiser les cibles de rendu à l’écran.
	ID3D11RenderTargetView *const targets[1] = { m_deviceResources->GetBackBufferRenderTargetView() };
	context->OMSetRenderTargets(1, targets, m_deviceResources->GetDepthStencilView());

	// Effacer la mémoire tampon d’arrière-plan et la vue du stencil de profondeur.
	context->ClearRenderTargetView(m_deviceResources->GetBackBufferRenderTargetView(), DirectX::Colors::CornflowerBlue);
	context->ClearDepthStencilView(m_deviceResources->GetDepthStencilView(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	// Afficher les objets de scène.
	// TODO: remplacez ceci par vos fonctions de rendu de contenu d'application.
	m_sceneRenderer->Render();
	m_fpsTextRenderer->Render();

	return true;
}

// Avertit les convertisseurs que les ressources du périphérique doivent être libérées.
void ZeroDarkThirtyMain::OnDeviceLost()
{
	m_sceneRenderer->ReleaseDeviceDependentResources();
	m_fpsTextRenderer->ReleaseDeviceDependentResources();
}

// Avertit les convertisseurs que les ressources du périphérique seront peut-être recréées.
void ZeroDarkThirtyMain::OnDeviceRestored()
{
	m_sceneRenderer->CreateDeviceDependentResources();
	m_fpsTextRenderer->CreateDeviceDependentResources();
	CreateWindowSizeDependentResources();
}
