#pragma once

#include <string>

namespace sf {
class Event;
}

namespace Engine {
enum class EventType {
	// We can map unsupported events to None and ignore them
	None = 0,

	// Window events
	WindowClose,
	WindowResize,
	WindowFocus,
	WindowLostFocus,
	WindowMoved,

	// Update events, in case we need them
	AppTick,
	AppUpdate,
	AppRender,

	// Keyboard events
	KeyPressed,
	KeyReleased,

	// Mouse events
	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved,
	MouseScrolled
};

class Event {
private:
	EventType _type;

public:
	Event(sf::Event &event);

	EventType Type() const;

	std::string toString() const;
};
} // namespace Engine
