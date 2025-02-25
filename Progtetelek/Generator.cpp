#include "Generator.h"
#include <random>

int generateRandom(std::mt19937 generator, std::uniform_int_distribution<int> dist)
{
	return dist(generator);
}