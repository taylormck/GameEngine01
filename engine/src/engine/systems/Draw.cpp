
#include "Draw.hpp"

#include "SFML/Graphics/CircleShape.hpp"

namespace Engine {
void Draw(sf::RenderWindow &window, const Transform2D &transform, const Circle &circle) {
	// TODO: it's probably best to save this somewhere and reuse it instead
	// of recreating it every frame.
	// This implementation is just to get up & running as fast as possible.
	sf::CircleShape shape = sf::CircleShape(circle.Radius);
	shape.setOrigin(transform.Position.x, transform.Position.y);
	shape.setScale(transform.Scale.x, transform.Scale.y);
	shape.setRotation(transform.Rotation);
	shape.setPosition(transform.Position.x, transform.Position.y);
	shape.setFillColor(sf::Color(circle.Color.x, circle.Color.y, circle.Color.z));

	window.draw(shape);
}
} // namespace Engine
