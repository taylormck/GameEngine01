/**
 * @file Implementation of the Engine::Application class
 */

#include "Application.hpp"
#include "Log.hpp"
#include "engine/events/Event.hpp"
#include <SFML/Graphics.hpp>

// TODO read these from a config/data file of some sort
constexpr int screenWidth = 800;
constexpr int screenHeight = 600;

namespace Engine {
Application::Application() {}

Application::~Application() {}

void Application::Run() {
	ENGINE_LOG_INFO("Running application");
	ENGINE_LOG_INFO("Creating window with size {}x{}", screenWidth, screenHeight);

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML window");

	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	sf::Clock clock;

	Init();

	while (window.isOpen()) {
		sf::Time delta = clock.restart();
		sf::Event event;

		while (window.pollEvent(event) && !_shouldClose) {
			Event engineEvent = Event(event);

			// Ignore unsupported events
			if (engineEvent.Type() != EventType::None) {
				ENGINE_LOG_INFO("Event: {}", engineEvent.toString());
				HandleEvent(engineEvent);
			}
		}

		// Break out of the loop if the window is closed
		if (_shouldClose) {
			window.close();
			break;
		}

		Update(delta.asSeconds());

		window.clear();

		Draw();

		window.display();
	}
}

void Application::Close() { _shouldClose = true; }

} // namespace Engine
