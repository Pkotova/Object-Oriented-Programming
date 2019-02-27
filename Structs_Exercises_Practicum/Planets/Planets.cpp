// Planets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;

const int N = 2;

struct Planet 
{
	char name[32];
	double distance; // from the Sun
	double diameter;
	double weight;
};

void input(Planet* planet, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Planet: " << i + 1 << endl;
		cout << "*************" << endl;
		cout << "Name: ";
		cin.get();
		cin.getline(planet[i].name, 32);
		cout << "Distance from the Sun: ";
		cin >> planet[i].distance;
		cout << "Diameter: ";
		cin >> planet[i].diameter;
		cout << "Weight:  ";
		cin >> planet[i].weight;
		cout << "_______________" << endl;
	}
}
void outputSingle(Planet planet, int n)
{
		cout <<"Name: " <<planet.name << endl;
		cout <<"Distance from the Sun: "<< planet.distance << endl;
		cout <<"Diameter: "<< planet.diameter << endl;
		cout << "Weight: "<<planet.weight<< endl;
}
void output(Planet * planet, int n)
{
	cout << "+------------------------------------------+" << endl;
	cout << left << setw(10) << "NAME"
		<< left << setw(10) << "DISTANCE"
		<< left << setw(10) << "DIAMETER"
		<< left << setw(10) << "WEIGHT"

		<< left << setw(26) << "   |" << endl;
	cout << "+------------------------------------------+" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << left << setw(10) << planet[i].name
			<< left << setw(10) << planet[i].distance
			<< left << setw(10) << planet[i].diameter
			<< left << setw(10) << planet[i].weight
			<< left << setw(23) << "   |" << endl;

	}
	cout << "+------------------------------------------+" << endl;
}
void secondsToPlanet(Planet * planet, int n)
{
	//TODO 
	int speed = 299792;
	for (int i = 0; i < n; i++)
	{
		cout << "Sunlight to " << planet[i].name << " in seconds is: ";
		cout << speed / planet[i].distance << endl;
	}
}
Planet maxDiameter(Planet * planet, int n)
{
	int max = planet[0].diameter;
	Planet currentPlanet = planet[0];
	for (int i = 1; i < n; i++)
	{
		if (planet[i].diameter >= max)
		{
			max = planet[i].diameter;
			currentPlanet = planet[i];
		}
	}
	cout << "Max diameter: " << endl;
	return currentPlanet;
}
Planet minWeight(Planet * planet, int n)
{
	int min = planet[0].weight;
	Planet currentPlanet = planet[0];
	for (int  i = 1; i < n; i++)
	{
		if (planet[i].weight < min)
		{
			min = planet[i].weight;
			currentPlanet = planet[i];
		}
	}
	return currentPlanet;
}
Planet sunlightLast(Planet * planet, int n)
{
	int speed = 299792;
	double minSunlightSpeed = planet[0].distance / speed;
	Planet currentPlanet = planet[0];

	for (int i = 1; i < n; i++)
	{
		if (minSunlightSpeed >= speed / planet[i].distance)
		{
			currentPlanet = planet[i];
		}
	}
	cout << endl;
	cout << "Sunrise Last:" << endl;
	cout << endl;
	return currentPlanet;
}
Planet sunlightFirst(Planet * planet, int n)
{
	int speed = 299792;
	double maxSunlightSpeed = planet[0].distance / speed;
	Planet currentPlanet = planet[0];

	for (int i = 1; i < n; i++)
	{
		if (maxSunlightSpeed <= speed / planet[i].distance)
		{
			currentPlanet = planet[i];
		}
	}
	cout << endl;
	cout << "Sunrise first: ";
	cout << endl;
	return currentPlanet;
}
void sortPlanets(Planet * planet, int n)
{
	for (int i = 0; i < n; i++)
	{

	}
}
int main()
{
	Planet planet[N];
	input(planet, N);
	output(planet, N);
	secondsToPlanet(planet, N);
	outputSingle(maxDiameter(planet,N),N);
	outputSingle(sunlightFirst(planet, N), N);
	outputSingle(sunlightLast(planet, N), N);

	return 0;
}

