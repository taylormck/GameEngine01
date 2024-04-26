/**
 * @file The base game object class
 */

#pragma once

#include "engine/components/Component.hpp"
#include <memory>
#include <vector>

#include <glm/glm.hpp>

namespace Engine {
class GameObject {
	std::vector<std::shared_ptr<Component>> _components;

public:
	void Update(float delta) {
		for (const auto component : _components) {
			component->Update(delta);
		}
	}

	void Draw(sf::RenderWindow &window) const {
		for (const auto component : _components) {
			component->Draw(window);
		}
	}

	void AddComponent(std::shared_ptr<Component> component) { _components.push_back(component); }
};
} // namespace Engine
