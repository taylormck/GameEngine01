/**
 * @file Singleton for generating random numbers
 */

#ifndef RANDOM_NUMBER_GENERATOR_HPP
#define RANDOM_NUMBER_GENERATOR_HPP

#include <random>

namespace Engine {
class RandomNumberGenerator {
	std::random_device _randomDevice;
	std::mt19937_64 _randomNumberEngine;

public:
	RandomNumberGenerator() : _randomNumberEngine(_randomDevice()) {}

	static RandomNumberGenerator &GetDefaultGenerator() {
		static RandomNumberGenerator instance;

		return instance;
	}

	RandomNumberGenerator(RandomNumberGenerator const &) = delete;
	void operator=(RandomNumberGenerator const &) = delete;

	static int GetRandomInt(int low, int high) {
		std::uniform_int_distribution distribution(low, high);

		return distribution(GetDefaultGenerator()._randomNumberEngine);
	}

	static float GetRandomFloat(float low, float high) {
		std::uniform_real_distribution distribution(low, high);
		return distribution(GetDefaultGenerator()._randomNumberEngine);
	}
};
} // namespace Engine

#endif // RANDOM_INT_GENERATOR_HPP
