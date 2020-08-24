#include <OEP.h>

class ExampleLayer : public oep::Layer 
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		OEP_INFO("ExampleLayer::Update");
	}

	void OnEvent(oep::Event& event) override
	{
		OEP_TRACE("{0}", event);
	}
};

class Sandbox : public oep::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new oep::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

oep::Application* oep::CreateApplication()
{
	return new Sandbox();
}