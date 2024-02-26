#include "fnpch.h"
#include "Application.h"

#include "Fern/Events/ApplicationEvent.h"
#include "Fern/Log.h"

namespace Fern {

	Application::Application() {

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}