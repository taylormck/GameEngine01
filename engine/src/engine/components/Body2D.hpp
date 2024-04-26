#pragma once

#include "Component.hpp"
#include <glm/glm.hpp>

namespace Engine {

struct Transform2D {
	glm::vec2 position;
	float rotation;
	glm::vec2 scale;
};

class Body2D : public Component {
private:
	Transform2D _transform;
	glm::vec2 _velocity;

public:
	Body2D(Transform2D transform, glm::vec2 velocity) :
		_transform(transform), _velocity(velocity) {}

	Body2D(Transform2D transform) : Body2D(transform, glm::vec2(0.0f, 0.0f)) {}

	Body2D(glm::vec2 position, float rotation, glm::vec2 scale, glm::vec2 velocity) :
		Body2D({position, rotation, scale}, velocity) {}

	Body2D(glm::vec2 position, float rotation, glm::vec2 scale) :
		Body2D({position, rotation, scale}, glm::vec2(0.0f, 0.0f)) {}

	Body2D(glm::vec2 position) :
		Body2D({position, 0.0f, glm::vec2(0.0f, 0.0f)}, glm::vec2(0.0f, 0.0f)) {}

	Body2D() : Body2D(glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(1.0f, 1.0f)) {}

	void Update(float delta) override { _transform.position += _velocity * delta; }

	void Draw(sf::RenderWindow &window) const override {}

	Transform2D &Transform() { return _transform; }

	void Transform(Transform2D transform) { _transform = transform; }

	glm::vec2 &Velocity() { return _velocity; }

	void Velocity(glm::vec2 velocity) { _velocity = velocity; }
};

} // namespace Engine
