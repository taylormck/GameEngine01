/**
 * @file A system to move objects based on their velocity
 */

#pragma once

#include "engine/components/Transform2D.hpp"
#include "engine/components/Velocity.hpp"

namespace Engine {
void Move(Transform2D &transform, const Velocity &velocity, float delta);
}
