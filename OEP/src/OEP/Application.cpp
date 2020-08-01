#include "oeppch.h"

#include "Application.h"

#include "OEP/Events/ApplicationEvent.h"
#include "OEP/Log.h"

namespace oep
{
	Application::Application()
	{

	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		OEP_TRACE(e);

		while (true);
	}
};
