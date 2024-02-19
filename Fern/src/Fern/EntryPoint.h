#pragma once

#ifdef FN_PLATFORM_WINDOWS

extern Fern::Application* Fern::CreateApplication();
int main(int argc, char** argv) {
	auto app = Fern::CreateAppplication();
	app->Run();
	delete app;
}

#endif