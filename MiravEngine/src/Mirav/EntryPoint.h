#pragma once

#ifdef MV_PLATFORM_WINDOWS

extern Mirav::Application* Mirav::CreateApplication();

int main(int argc, char** argv)
{
	Mirav::Log::Init();
	MV_CORE_INFO("good");
	MV_CRITICAL("not good");
	auto app = Mirav::CreateApplication();
	app->Run();
	delete app;
}

#endif