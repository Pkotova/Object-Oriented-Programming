// Planet-Struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct Planet
{
	char name[30];
	double distance;
	double mass;
	double diameter;

	void input();
	void output() const;
	double secondsToPlanet() const;
};

void Planet::input()
{
	cout << " Planet's Name: ";
	cin.get();
	cin.getline(name, 30);
	/*cout << " Distance: ";
	cin >> distance;
	cout << " Mass: ";
	cin >> mass;
	cout << " Diameter: ";
	cin >> diameter;*/
}

void Planet::output()const
{
	cout <<"Planet's Name: "<<name << endl;
	//cout << "Distance: " << distance << endl;
	//cout << "Mass: " << mass << endl;
	//cout << "Diameter: " << diameter << endl;
}

double Planet::secondsToPlanet() const
{
	const int lightSpeed = 299792;
	double seconds = distance / lightSpeed;
	return seconds;
}

struct MyPlanet
{
	char ownerName[30];
	int ownerAge;
	Planet planet;

	void enterData();
	void outputData() const;
};

void MyPlanet::enterData()
{
	cout << "Owner Name: ";
	cin.getline(ownerName, 30);
	cout << "Owner Age: ";
	cin >> ownerAge;
	planet.input();
	cin.ignore();
}
void MyPlanet::outputData()const
{
	cout << "Owner Name: " << ownerName << endl;
	cout << "Owner Age: " << ownerAge << endl;
	planet.output();
}

void sort(MyPlanet ourSpace[100], int size )
{
	cout << "Sort" << endl;
	cout << "____________" << endl;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(ourSpace[i].ownerName,ourSpace[i++].ownerName) > 0)
		{
			swap(ourSpace[i].ownerName, ourSpace[i++].ownerName);
		}
	}
	for (int i = 0; i < size; i++)
	{
		ourSpace[i].outputData();
	}
}

void report(MyPlanet ourSpace[100], int size)
{
	cout << "Report: " << endl;
	cout << "_______________" << endl;
	for (int i = 0; i < size; i++)
	{
		if (ourSpace[i].ownerAge > 20)
		{
			ourSpace[i].outputData();
		}
	}
}

int main()
{
	MyPlanet ourSpace[100];
	for (int i = 0; i < 2; i++)
	{
		ourSpace[i].enterData();
	}
	sort(ourSpace, 2);
	cout << endl;
	report(ourSpace, 2);
}

