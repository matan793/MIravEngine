#pragma once

#ifdef MV_PLATFORM_WINDOWS

extern Mirav::Application* Mirav::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Mirav::CreateApplication();
	app->Run();
	delete app;
}

#endif