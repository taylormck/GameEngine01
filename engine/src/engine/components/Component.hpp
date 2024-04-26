/**
 * @file header file for base component class
 */

#pragma once

#include <SFML/Graphics.hpp>

namespace Engine {
class Component {
public:
	virtual void Update(float delta) = 0;
	virtual void Draw(sf::RenderWindow &window) const = 0;
};
} // namespace Engine
