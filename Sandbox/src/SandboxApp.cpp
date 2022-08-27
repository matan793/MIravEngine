#include <Mirav.h>

class Sandbox : public Mirav::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}

};

Mirav::Application* Mirav::CreateApplication()
{
	return new Sandbox();
}