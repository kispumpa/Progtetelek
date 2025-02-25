#include <random>
#include <vector>
#include <iostream>

std::vector<int> RandomFeltolto()
{
	std::vector<int> tomb; //10 elemu tomb
	std::random_device r; //random device
	std::mt19937 generator(r()); //random generator
	std::uniform_int_distribution<int> dist(1, 100); //random "intervallum"

	for (size_t i = 0; i < 10; i++)
	{
		tomb.push_back(dist(generator));
	}

	return tomb;
}
std::vector<int> Manualis()
{
	std::cout << "10 erteket kell megadnod" << std::endl;
	std::vector<int> vektor;

	for (size_t i = 0; i < 10; i++)
	{
		int bem;
		std::cout << i + 1;
		std::cout <<". ertek: ";
		std::cin >> bem;
		vektor.push_back(bem);
	}
	return vektor;
}

int main()
{
	std::vector<int> vek(10);

	std::cout << "Random szamu vektort szeretnel (R), vagy te adod meg az ertekeket (M)? \nIrd be a betut: ";
	char bemenet;
	std::cin >> bemenet;

	if (bemenet == 'R')
		vek = RandomFeltolto();
	else if (bemenet != 'M')
		std::cout << "Rossz erteket adtal meg" << std::endl;
	else
		vek = Manualis();

	vek.size();
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << vek[i] << std::endl;
	}

}