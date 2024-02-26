#pragma once

#ifdef FN_PLATFORM_WINDOWS

extern Fern::Application* Fern::CreateApplication();

int main(int argc, char** argv) {

	Fern::Log::Init();
	FN_CORE_WARN("Inititalized Log!");
	FN_INFO("Hello!");

	auto app = Fern::CreateApplication();
	app->Run();
	delete app;
}

#endif