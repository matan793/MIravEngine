#pragma once

#ifdef MV_PLATFORM_WINDOWS

extern Mirav::Application* Mirav::CreateApplication();

int main(int argc, char** argv)
{
	Mirav::Log::Init();
	MV_CORE_WARN("Initialized Log!");
	int a = 5;
	MV_INFO("Hello! Var={0}", a);
	
	auto app = Mirav::CreateApplication();
	app->Run();
	delete app;
}

#endif