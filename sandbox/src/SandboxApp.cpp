#include <Engine.hpp>
#include <glm/glm.hpp>
#include <memory>
#include <vector>

class Sandbox : public Engine::Application {
private:
	std::vector<Engine::GameObject> _gameObjects;

public:
	Sandbox() {}

	~Sandbox() {}

	void Init() override {
		APP_LOG_INFO("Initializing application");

		glm::vec3 circle_color(0.5f, 0.2f, 0.3f);

		Engine::GameObject first_circle;
		first_circle.AddComponent(std::make_shared<Engine::Body2D>(
			glm::vec2(1.0f, 1.0f),
			0.0f,
			glm::vec2(1.0f, 1.0f),
			glm::vec2(2.0f, 1.0f)
		));
		first_circle.AddComponent(std::make_shared<Engine::Circle>(5.0f, circle_color));

		_gameObjects.push_back(first_circle);
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
		for (auto gameObject : _gameObjects) {
			gameObject.Update(delta);
		}
	}

	void Draw(sf::RenderWindow &window) override {
		for (const auto gameObject : _gameObjects) {
			gameObject.Draw(window);
		}
	}
};

Engine::Application *CreateApplication() { return new Sandbox(); }
