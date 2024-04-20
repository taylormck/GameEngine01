#pragma once

namespace Engine {
class Application {
protected:
	virtual void Init() = 0;
	virtual void Update(float delta) = 0;
	virtual void Draw() = 0;

public:
	Application();
	virtual ~Application();

	void Run();
};

} // namespace Engine

Engine::Application *CreateApplication();
