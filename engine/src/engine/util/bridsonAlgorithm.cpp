/**
 * @file implementation for Bridson algorithm
 *
 */

#include "./bridsonAlgorithm.hpp"
#include "./RandomNumberGenerator.hpp"

constexpr int maxAttempts = 1000;

namespace Engine {

std::vector<sf::Vector2i>
generate2DPoints(int top, int left, int bottom, int right, float minimumDistance) {
	int minimumDistanceSquared = minimumDistance * minimumDistance;
	/* float cellSize = minimumDistance / sqrt(2); */

	std::vector<sf::Vector2i> points;

	points.emplace_back(
		Engine::RandomNumberGenerator::GetRandomInt(left, right),
		Engine::RandomNumberGenerator::GetRandomInt(top, bottom)
	);

	for (int i = 0; i < points.size(); ++i) {
		auto currentPoint = points[i];

		float epsilon = 0.00001f;
		float seed = Engine::RandomNumberGenerator::GetRandomFloat(0, 1);

		for (int attempt = 0; attempt < maxAttempts; ++attempt) {
			float theta = 2 * std::numbers::pi * (seed + (float)attempt / maxAttempts);
			float r = minimumDistance + epsilon;

			sf::Vector2i newPoint(
				currentPoint.x + r * std::cos(theta),
				currentPoint.y + r * std::sin(theta)
			);

			if (newPoint.y < top || newPoint.y > bottom || newPoint.x < left ||
				newPoint.x > right) {
				continue;
			}

			bool isTooCloseToAnotherPoint = false;

			// TODO limit this search to points in nearby grid cells
			for (const auto &point : points) {
				sf::Vector2 diff = newPoint - point;
				float distanceSquared = diff.x * diff.x + diff.y * diff.y;

				if (distanceSquared < minimumDistanceSquared) {
					isTooCloseToAnotherPoint = true;
					continue;
				}
			}

			if (!isTooCloseToAnotherPoint) {
				points.push_back(newPoint);
			}
		}
	}

	return points;
}

} // namespace Engine
