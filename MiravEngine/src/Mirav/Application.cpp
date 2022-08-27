#include "mvpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
namespace Mirav {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MV_WARN(e);
		std::cout << "nigger ";
		while (true);
	}

}