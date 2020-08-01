#pragma once

#ifdef OEP_PLATFORM_WINDOWS

extern oep::Application* oep::CreateApplication();

int main(int argc, char** argv)
{
	oep::Log::Init();
	OEP_CORE_WARN("Initialized log!");
	int a = 5;
	OEP_INFO	 ("Hello! Var={0}", a);

	auto app = oep::CreateApplication();
	app->Run();
	delete app;
}

#endif