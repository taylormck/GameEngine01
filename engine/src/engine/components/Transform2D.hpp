/**
 * @file A component to represent a game object's position
 */

#pragma once

#include <glm/glm.hpp>

namespace Engine {
struct Transform2D {
	glm::vec2 Position;
	float Rotation;
	glm::vec2 Scale;

	Transform2D(glm::vec2 position, float rotation, glm::vec2 scale) :
		Position(position), Rotation(rotation), Scale(scale) {}
};
} // namespace Engine
