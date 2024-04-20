/**
 * @file Tool to implement bridson algorithm for evenly distributed points
 */

#ifndef BRIDSON_ALGORITHM_HPP
#define BRIDSON_ALGORITHM_HPP

#include <SFML/Graphics.hpp>
#include <vector>

namespace Engine {

std::vector<sf::Vector2<int>> generate2DPoints(
	int top,
	int left,
	int bottom,
	int right,
	float minimumDistance
);

} // namespace Engine

#endif
