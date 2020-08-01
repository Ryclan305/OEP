#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace oep
{

	class OEP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		//To be defined in a client

	};

	Application* CreateApplication();

};