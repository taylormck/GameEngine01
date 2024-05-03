#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

namespace Engine {

struct Circle {
	float Radius;
	glm::u8vec3 Color;

	Circle(float radius, glm::u8vec3 color) : Radius(radius), Color(color) {}
};
} // namespace Engine
