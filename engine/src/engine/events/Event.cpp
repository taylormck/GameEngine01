/**
 * @file Implementation of Engine::Event
 */

#include "Event.hpp"
#include <SFML/Window/Event.hpp>

#include <format>

namespace Engine {

Event::Event(sf::Event &event) {
	switch (event.type) {
	case sf::Event::Closed:
		_type = EventType::WindowClose;
		break;

	case sf::Event::KeyPressed:
		_type = EventType::KeyPressed;
		break;

	case sf::Event::KeyReleased:
		_type = EventType::KeyReleased;
		break;

	default:
		_type = EventType::None;
	}
}

EventType Event::Type() const { return _type; }

std::string Event::toString() const {
	switch (_type) {
	case EventType::WindowClose:
		return "WindowClose";
	case EventType::KeyPressed:
		return "KeyPressed";
	case EventType::KeyReleased:
		return "KeyReleased";
	default:
		return std::format("Unsupported Event");
	}
}

} // namespace Engine
