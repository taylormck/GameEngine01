/**
 * @file A component to add velocity to objects
 */

#pragma once

#include <glm/glm.hpp>

namespace Engine {
struct Velocity {
	glm::vec2 Value;

	Velocity(glm::vec2 velocity) : Value(velocity) {}

	Velocity() : Value({0.0f, 0.0f}) {}
};
} // namespace Engine
