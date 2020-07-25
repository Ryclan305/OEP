#include <OEP.h>

class Sandbox : public oep::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

oep::Application* oep::CreateApplication()
{
	return new Sandbox();
}