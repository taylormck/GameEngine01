#include <Engine.hpp>
#include <glm/glm.hpp>

class Sandbox : public Engine::Application {
public:
	Sandbox() {}

	~Sandbox() {}

	void Init() override {
		APP_LOG_INFO("Initializing application");

		glm::u8vec3 circle_color(123, 25, 30);

		Application::AddGameObject(
			Engine::Transform2D(glm::vec2(100.0f, 100.0f), 45.0f, glm::vec2(2.0f, 1.0f)),
			Engine::Velocity(glm::vec2(10.0f, 10.0f)),
			Engine::Circle(50.0f, circle_color)
		);
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

	void Update(float delta) override {}

	/* void Draw(sf::RenderWindow &window) override {} */
};

Engine::Application *CreateApplication() { return new Sandbox(); }
