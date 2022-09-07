#pragma once

#include "Core.h"


#include "Mirav/LayerStack.h"
#include "Mirav/Events/Event.h"
#include "Mirav/Events/ApplicationEvent.h"


#include "Window.h"

namespace Mirav {

	class Mirav_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}