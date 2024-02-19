#include <Fern.h>

class Sandbox : public Fern::Application{
public:
	Sandbox();
	~Sandbox();

private:

};

void main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}