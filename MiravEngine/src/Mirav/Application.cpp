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
		WindowCloseEvent e = WindowCloseEvent();
		MV_CRITICAL(e);
		while (true);
	}

}