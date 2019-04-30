#include "stdafx.h"
#include<iostream>
#include "IceCream.h"

using namespace std;

IceCream::IceCream(const IceCreamFlavour& newFlavour, const int& newBalls, const char* newName)
	: name(nullptr)
{
	setFlavour(newFlavour);
	setBalls(newBalls);
	setName(newName);
}

IceCream::IceCream(const IceCream& other) 
	     : IceCream(other.flavour, other.balls, other.name)
{}

IceCream& IceCream::operator= (const IceCream& other)
{
	if (this != &other)
	{
		setFlavour(other.flavour);
		setBalls(other.balls);
		setName(other.name);
	}
	return *this;
}

void IceCream::setFlavour(const IceCreamFlavour& newFlavour)
{
	if(newFlavour.flavourName != '\0' || newFlavour.pricePerBall > 0.0)  // data validation
		this->flavour = newFlavour;
}

IceCreamFlavour IceCream::getFlavour() const
{
	return this->flavour;
}

void IceCream::setBalls(const int& newBalls)
{
	if(newBalls > 0) this->balls = newBalls; // data validation
}

int IceCream::getBalls() const
{
	return this->balls;
}

void IceCream::setName(const char* name)
{
	if (name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

const char* IceCream::getName() const
{
	return this->name;
}

double IceCream::getPrice() const
{
	return this->balls * this->flavour.pricePerBall;
}

void IceCream::create()
{
	cout << endl << "Flavour: ";
	cin.ignore();
	cin.getline(flavour.flavourName, 32);

	cout << "Price for ball: ";
	cin >> flavour.pricePerBall;

	cout << "Amount of balls:: ";
	cin >> balls;

	cout << "Name: ";
	cin.ignore();
	cin.getline(name, strlen(name) + 1);
}

void IceCream::print() const
{
	cout << "Flavour name: " << flavour.flavourName << endl;
	cout << "Price for a ball: " << flavour.pricePerBall << endl;
	cout << "Balls amount " << balls << endl;
	cout << "Name: " << name << endl;
	cout << endl;
}

IceCream::~IceCream()
{
	delete[] this->name; //delete using data
}