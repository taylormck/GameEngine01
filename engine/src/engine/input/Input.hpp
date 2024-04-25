#include "SFML/Window/Keyboard.hpp"
#include <SFML/Graphics.hpp>

namespace Engine {
enum Keyboard { Escape = sf::Keyboard::Escape };

class Input {
	// TODO: implement IsJustPressed map
public:
	static bool IsKeyPressed(Keyboard key);
};
} // namespace Engine
