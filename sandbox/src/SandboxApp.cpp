#include <Engine.hpp>

class Sandbox : public Engine::Application {
public:
	Sandbox() {}

	~Sandbox() {}

	void Init() override {
		// TODO initialize stuff
		APP_LOG_INFO("Initializing application");
	}

	void Update(float delta) override {
		// TODO do stuff
		// TODO update all the things
	}

	void Draw() override {
		// TODO do
		// TODO draw all the things
	}
};

Engine::Application *CreateApplication() { return new Sandbox(); }
