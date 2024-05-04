
#include "Move.hpp"

namespace Engine {
void Move(Transform2D &transform, const Velocity &velocity, float delta) {
	transform.Position += velocity.Value * delta;
}
} // namespace Engine
