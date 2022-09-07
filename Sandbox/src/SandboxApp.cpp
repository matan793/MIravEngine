#include <Mirav.h>

class ExampleLayer : public Mirav::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		MV_INFO("ExampleLayer::Update");
	}

	void OnEvent(Mirav::Event& event) override
	{
		MV_TRACE("{0}", event);
	}

};

class Sandbox : public Mirav::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Mirav::Application* Mirav::CreateApplication()
{
	return new Sandbox();
}