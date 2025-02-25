#include "Generator.h"
#include <vector>
#include <iostream>

std::vector<int> RandomFeltolto()
{
	std::vector<int> tomb(10); //10 elemu tomb
	std::random_device r; //random device
	std::mt19937 generator(r()); //random generator
	std::uniform_int_distribution<int> dist(1, 100); //random "intervallum"

	for (size_t i = 0; i < 10; i++)
	{
		tomb.push_back(generateRandom(generator, dist));
	}

	return tomb;
}
//std::vector<int> Manualis()
//{
//
//}

int main()
{
	std::vector<int> vek(10);

	std::cout << "Random szamu vektort szeretnel (R), vagy te adod meg az ertekeket (M)? \nIrd be a betut: ";
	char bemenet;
	std::cin >> bemenet;

	if (bemenet == 'R')
		std::cout << "R-t adott meg";
	//vek = RandomFeltolto();
	else if (bemenet != 'M')
		std::cout << "Rossz erteket adtal meg" << std::endl;
	else
		std::cout << "M-et adott meg";
}