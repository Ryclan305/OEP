#pragma once

#ifdef OEP_PLATFORM_WINDOWS

extern oep::Application* oep::CreateApplication();

int main(int argc, char** argv)
{
	auto app = oep::CreateApplication();
	app->Run();
	delete app;
}

#endif