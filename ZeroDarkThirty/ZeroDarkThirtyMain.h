#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\Sample3DSceneRenderer.h"
#include "Content\SampleFpsTextRenderer.h"

// Affiche le contenu Direct2D et 3D à l'écran.
namespace ZeroDarkThirty
{
	class ZeroDarkThirtyMain : public DX::IDeviceNotify
	{
	public:
		ZeroDarkThirtyMain(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~ZeroDarkThirtyMain();
		void CreateWindowSizeDependentResources();
		void Update();
		bool Render();

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();

	private:
		// Pointeur mis en cache vers les ressources du périphérique.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// TODO: remplacez par vos propres convertisseurs de contenu.
		std::unique_ptr<Sample3DSceneRenderer> m_sceneRenderer;
		std::unique_ptr<SampleFpsTextRenderer> m_fpsTextRenderer;

		// Minuteur de boucle de rendu.
		DX::StepTimer m_timer;
	};
}