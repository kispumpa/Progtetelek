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
int Sorozatszamitas(std::vector<int> v)
{
	int szum = 0;
	for (size_t i = 0; i < 10; i++)
	{
		szum += v[i];
	}
	return szum;
}
int Megszamlalas(std::vector<int> v)
{
	int db = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (v[i] % 2 == 0) //paros-e az adott elem
			db++;
	}

	return db;
}
int Maximumkivalasztas(std::vector<int> v)
{
	int max = 0;
	for (size_t i = 1; i < 10; i++)
	{
		if (v[i] > v[max])
			max = i;
	}

	return max;
}

int main()
{
	std::vector<int> vek(10);

	std::cout << "Random szamu vektort szeretnel (r), vagy te adod meg az ertekeket (m)? \nIrd be a betut: ";
	char bemenet;
	std::cin >> bemenet;
	bool veletlen = false;

	if (bemenet == 'r')
	{
		vek = RandomFeltolto();
		veletlen = true;
	}

	else if (bemenet != 'm')
		std::cout << "Rossz erteket adtal meg" << std::endl;
	else
		vek = Manualis();

	if (veletlen)
	{
		for (size_t i = 0; i < 10; i++)
		{
			std::cout << i + 1;
			std::cout << ". ertek: ";
			std::cout << vek[i] << std::endl;
		}
	}

	std::cout << "\nElemek osszege: ";
	std::cout << Sorozatszamitas(vek) << std::endl;

	std::cout << "\nParos szamok darabszama: ";
	std::cout << Megszamlalas(vek) << std::endl;

	int idx = Maximumkivalasztas(vek);
	std::cout << "\nLegnagyobb elem indexe: ";
	std::cout << idx;
	std::cout << ". és erteke: ";
	std::cout << vek[idx] << std::endl;
}