/**
 * @file A system for drawing an object
 */

#pragma once

#include "engine/components/Circle.hpp"
#include "engine/components/Transform2D.hpp"
#include <SFML/Graphics.hpp>

namespace Engine {
void Draw(sf::RenderWindow &window, const Transform2D &transform, const Circle &circle);
} // namespace Engine
