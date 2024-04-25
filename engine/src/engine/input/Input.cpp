/**
 * @file source file for Input manager
 */

#include "Input.hpp"

namespace Engine {

bool Input::IsKeyPressed(Keyboard key) {
	return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key);
};
} // namespace Engine
