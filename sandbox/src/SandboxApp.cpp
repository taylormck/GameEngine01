#include <Engine.hpp>

class Sandbox : public Engine::Application {
public:
	Sandbox() {}

	~Sandbox() {}

	void Init() override {
		APP_LOG_INFO("Initializing application");

		// TODO initialize stuff
	}

	void HandleEvent(Engine::Event &event) override {
		switch (event.Type()) {
		case Engine::EventType::WindowClose:
			Close();
			break;
		case Engine::EventType::KeyPressed:
			if (Engine::Input::IsKeyPressed(Engine::Keyboard::Escape)) {
				Close();
			}
			break;
		default:
			// TODO handle missing event types
		}
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
