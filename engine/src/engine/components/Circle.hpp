#pragma once

#include "Component.hpp"
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

namespace Engine {

class Circle : public Component {
private:
	sf::CircleShape _shape;

public:
	Circle(float radius, glm::vec3 color) : _shape(radius) {
		glm::vec3 new_color = color * 255.0f;
		new_color = glm::round(new_color);

		_shape.setFillColor(sf::Color(new_color.x, new_color.y, new_color.z));
	}

	void Update(float delta) {}

	void Draw(sf::RenderWindow &window) const { window.draw(_shape); }
};

} // namespace Engine
