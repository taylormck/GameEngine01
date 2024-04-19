#include <SFML/Graphics.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <vector>

#include "SFML/Window/Keyboard.hpp"
#include "loggers/Log.hpp"
#include "noiseGenerators/bridsonAlgorithm.hpp"

constexpr int screenWidth = 800;
constexpr int screenHeight = 600;
constexpr float circleRadius = 10.0f;

int main() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML window");

	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	sf::Clock clock;

	std::vector<sf::Vector2i> points =
		Engine::generate2DPoints(0, 0, screenHeight, screenWidth, 2.5 * circleRadius);

	ENGINE_LOG_INFO("Points generated: {}", points.size());

	std::vector<sf::CircleShape> shapes;

	for (auto point : points) {
		shapes.emplace_back(circleRadius);

		shapes.back().setPosition(point.x, point.y);
		shapes.back().setFillColor(sf::Color::Green);
	}

	while (window.isOpen()) {
		sf::Event event;
		sf::Time delta = clock.restart();

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
		}

		window.clear();

		for (const auto &shape : shapes) {
			window.draw(shape);
		}

		window.display();
	}

	return 0;
}
