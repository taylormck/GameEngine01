#include "Application.hpp"
#include "Log.hpp"
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

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
		}

		Update(delta.asSeconds());

		window.clear();

		Draw();

		window.display();
	}
}

} // namespace Engine
