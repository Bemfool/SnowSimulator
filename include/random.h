#pragma once
#include <random>
#include <chrono>


/* Function: uniform_random
 * Usage: float n = uniform_random(min, max);
 ***********************************************************************
 * Get a random number in uniform distribution between min and max.
 */

inline float uniform_random(float min, float max) {
	unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 rand_generator(seed);
	std::uniform_real_distribution<float> dist(min, max);
	return dist(rand_generator);
}


/* Function: normal_random
* Usage: float n = normal_random(avg, var);
***********************************************************************
* Get a random number in normal distribution with avg as average and var
* as variance.
*/

inline float normal_random(float avg, float var) {
	unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 rand_generator(seed);
	std::normal_distribution<float> dist(avg, var);
	return dist(rand_generator);
}