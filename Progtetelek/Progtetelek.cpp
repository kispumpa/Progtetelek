#include <random>
#include <vector>
#include <iostream>

std::vector<int> RandomFeltolto(int n)
{
	std::vector<int> tomb; //10 elemu tomb
	std::random_device r; //random device
	std::mt19937 generator(r()); //random generator
	std::uniform_int_distribution<int> dist(1, 100); //random "intervallum"

	for (size_t i = 0; i < n; i++)
	{
		tomb.push_back(dist(generator));
	}

	return tomb;
}
std::vector<int> Manualis(int n)
{
	std::cout << "10 erteket kell megadnod" << std::endl;
	std::vector<int> vektor;

	for (size_t i = 0; i < n; i++)
	{
		int bem;
		std::cout << i + 1;
		std::cout << ". ertek: ";
		std::cin >> bem;
		vektor.push_back(bem);
	}
	return vektor;
}
int Sorozatszamitas(std::vector<int> v, int n)
{
	int szum = 0;
	for (size_t i = 0; i < n; i++)
	{
		szum += v[i];
	}
	return szum;
}
int Megszamlalas(std::vector<int> v, int n)
{
	int db = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (v[i] % 2 == 0) //paros-e az adott elem
			db++;
	}

	return db;
}
int Maximumkivalasztas(std::vector<int> v, int n)
{
	int max = 0;
	for (size_t i = 1; i < n; i++)
	{
		if (v[i] > v[max])
			max = i;
	}

	return max;
}
bool PrimszamE(int x)
{
	int i = 2;

	while (i < x && x % i != 0)
		i++;
	bool prim = i == x;

	return prim;
}
int LinearisKereses(std::vector<int> v, int n)
{
	int i = 0;
	while (i < n && !PrimszamE(v[i]))
		i++;

	bool vanPrim = i <= n;

	if (vanPrim)
		return i;
	else
		return -1; //ilyen idx nem lehet
}

int main()
{
	const int n = 10;
	std::vector<int> vek(n);

	std::cout << "Random szamu vektort szeretnel (r), vagy te adod meg az ertekeket (m)? \nIrd be a betut: ";
	char bemenet;
	std::cin >> bemenet;
	bool veletlen = false;

	if (bemenet == 'r')
	{
		vek = RandomFeltolto(n);
		veletlen = true;
	}
	else if (bemenet != 'm')
		std::cout << "Rossz erteket adtal meg" << std::endl;
	else
		vek = Manualis(n);

	vek.shrink_to_fit();

	if (veletlen)
	{
		for (size_t i = 0; i < n; i++)
		{
			std::cout << i + 1;
			std::cout << ". ertek: ";
			std::cout << vek[i] << std::endl;
		}
	}

	std::cout << "\nElemek osszege: ";
	std::cout << Sorozatszamitas(vek, n) << std::endl;

	std::cout << "\nParos szamok darabszama: ";
	std::cout << Megszamlalas(vek, n) << std::endl;

	int idx = Maximumkivalasztas(vek, n);
	std::cout << "\nLegnagyobb elem indexe: ";
	std::cout << idx;
	std::cout << ". es erteke: ";
	std::cout << vek[idx] << std::endl;

	int primIdx = LinearisKereses(vek, n);
	if (primIdx < 0)
		std::cout << "\nNincs primszam a vektorban." << std::endl;
	else
	{
		std::cout << "\nElso primszam a vektorban: ";
		std::cout << vek[primIdx];
	}
}