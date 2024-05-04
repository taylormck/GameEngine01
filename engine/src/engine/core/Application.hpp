#pragma once

#include <SFML/Graphics.hpp>

#include "engine/components/Circle.hpp"
#include "engine/components/Transform2D.hpp"
#include "engine/components/Velocity.hpp"
#include <vector>

namespace Engine {
class Event;

class Application {
private:
	bool _shouldClose = false;
	std::vector<Transform2D> _transforms;
	std::vector<Circle> _circles;
	std::vector<Velocity> _velocities;

protected:
	virtual void Init() = 0;
	virtual void HandleEvent(Event &event) = 0;
	virtual void Update(float delta) = 0;

	virtual void ExecuteSystems(float delta);
	void Draw(sf::RenderWindow &window);
	void Close();
	void AddGameObject(Transform2D transform, Velocity velocity, Circle circle);

public:
	Application();
	virtual ~Application();

	void Run();
};

} // namespace Engine

Engine::Application *CreateApplication();
