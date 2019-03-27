// Fruit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

enum color {brown, green, orange, red, yellow};
enum is {yes, no};
const int MaxSIZE = 3;

color colorOfFruit(int index);
is isTrueOrFalse(int index);

struct Fruit 
{
	char name[32];
	color colorOfFruit;
	is annual;
	is prennial;
	is tropical;
};

void createFruit(Fruit& fruit)
{
	int index;

	cout << "Name: ";
	cin.get();
	cin.getline(fruit.name, 32);

	cout << "Color of fruit: ";
	cin >> index;
	fruit.colorOfFruit = colorOfFruit(index);

	cout << "Is annual (1 = yes/ 0 = no): ";
	cin >> index;
	fruit.annual = isTrueOrFalse(index);

	cout << "Is prennial (yes/no): ";
	cin >> index;
	fruit.prennial = isTrueOrFalse(index);

	cout << "Is tropical (yes/no): ";
	cin >> index;
	fruit.tropical = isTrueOrFalse(index);

}
is isTrueOrFalse(int index)
{
	switch (index)
	{
		case 0: return no;
		case 1: return yes;
		default: cout << "Wrong input! " << endl;
	}
}

color colorOfFruit(int index)
{
	switch (index)
	{
	case 0: return brown;
	case 1: return green;
	case 2: return orange;
	case 3: return red;
	case 4: return yellow;
	default: cout<< "Wrong input: " << endl;
		break;
	}
}
void readFruit(const Fruit& fruit)
{
	cout << "Name: " << fruit.name << endl;
	cout << " Color of fruit " << fruit.colorOfFruit << endl;
	cout << "Is annual: " << fruit.annual << endl;
	cout << " Is prennial: " << fruit.prennial << endl;
	cout << " Is tropical: " << fruit.prennial << endl;
}
void createPArray(Fruit* const fruit, int size, Fruit ** pFruits)
{
	for (int i = 0; i < size; i++)
	{
		pFruits[i] = &fruit[i];
	}
}
void sortFruits(Fruit ** pFruit, int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		Fruit * maxFruit = pFruit[i];
		int maxIndex = i;
		for (int j = i + 1 ; j < size; j++)
		{
			if (strcmp(maxFruit->name,pFruit[j]->name) == 1)
			{
				maxFruit = pFruit[j];
				maxIndex = j;
			}
		}
		swap(pFruit[i], pFruit[maxIndex]);
	}
}
int main()
{
	int size; 
	Fruit fruits[MaxSIZE];
	Fruit * pFruits[MaxSIZE];
	do
	{
		cout << "How many fruits do you have: ";
		cin >> size;
	} while (size < 1 || size > MaxSIZE);

	for (int i = 0; i < size; i++)
	{
		cout << "Fruit " << i + 1 << " : " << endl;
		cout << "_______________________" << endl;
		createFruit(fruits[i]);
	}
	cout << endl;

	createPArray(fruits, size, pFruits);
	sortFruits(pFruits, size);

	for (int i = 0; i < size; i++)
	{
		readFruit(*pFruits[i]);
	}


    return 0;
}

