#pragma once

namespace Engine {
class Event;

class Application {
private:
	bool _shouldClose = false;

protected:
	virtual void Init() = 0;
	virtual void HandleEvent(Event &event) = 0;
	virtual void Update(float delta) = 0;
	virtual void Draw() = 0;

	void Close();

public:
	Application();
	virtual ~Application();

	void Run();
};

} // namespace Engine

Engine::Application *CreateApplication();
