#include "mvpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include <GLFW/glfw3.h>


namespace Mirav {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		
		while (m_Running)
		{
			
			glClearColor(1, 1, 0.6, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			MV_INFO(GL_VERSION);
			m_Window->OnUpdate();
		};
	}

}