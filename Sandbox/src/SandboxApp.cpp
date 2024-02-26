#include "fnpch.h"
#include <Fern.h>

class Sandbox : public Fern::Application{
public:
	Sandbox(){}
	~Sandbox(){}

private:

};

Fern::Application* Fern::CreateApplication() {
	return new Sandbox();
}