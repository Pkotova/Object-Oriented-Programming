#include "stdafx.h"
#include "Fish.h"
#include<iostream>
using namespace std;

void Fish::copy(const Fish& other)
{
	setType(other.type);
	this->weight = other.weight;
	this->price = other.price;
}
void Fish::destroy()
{
	delete[] this->type;
}
Fish::Fish() : type(nullptr)
{
	setType("Default");
	setWeight(0.0);
	setPrice(0.0);
}
Fish::Fish(const Fish& other)
{
	copy(other);
}
Fish& Fish::operator=(const Fish& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
Fish::Fish(const char* newName, const double& newWeight, const double& newPrice) : type(nullptr)
{
	setType(newName);
	setWeight(newWeight);
	setPrice(newPrice);
}
void Fish::setType(const char* newType)
{
	if (newType != nullptr)
	{
		//destroy();
		this->type = new char[strlen(newType) + 1];
		strcpy_s(this->type, strlen(newType) + 1, newType);
	}
}
char* Fish::getType()const
{
	return this->type;
}
void Fish::setWeight(const double& newWeight)
{
	this->weight = newWeight;
}
double Fish::getWeight()const
{
	return this->weight;
}
void Fish::setPrice(const double& newPrice)
{
	this->price = newPrice;
}
double Fish::getPrice()
{
	return this->price;
}
Fish::~Fish()
{
	destroy();
}
ostream& operator<<(ostream& out, const Fish& current)
{
	out << "  -Type: " << current.type << endl
		<< "  -Weight: " << current.weight << endl
		<< "  -Price: " << current.price << endl;
	return out;
}
istream& operator>>(istream& in, Fish& current)
{
	cout << "Type: ";
	in >> current.type;
	cout << "Weight: ";
	in >> current.weight;
	cout << "Price: ";
	in >> current.price;
	return in;
}
bool operator<(const Fish& f1, const Fish& f2)
{
	return (f1.weight < f1.weight) ||
		strcmp(f1.type, f1.type) < 0;
}

bool operator>(const Fish& f1, const Fish& f2)
{
	return (f1.weight > f1.weight) ||
		strcmp(f1.type, f1.type) > 0;
}
bool operator<=(const Fish& f1, const Fish& f2)
{
	return (f1.weight <= f1.weight) ||
		strcmp(f1.type, f1.type) <= 0;
}
bool operator>=(const Fish& f1, const Fish& f2)
{
	return (f1.weight >= f1.weight) ||
		strcmp(f1.type, f1.type) >= 0;
}
bool operator==(const Fish& f1, const Fish& f2)
{
	return (f1.weight == f1.weight) &&
		strcmp(f1.type, f1.type) == 0;
}
bool operator!=(const Fish& f1, const Fish& f2)
{
	return (f1.weight != f1.weight) ||
		strcmp(f1.type, f1.type) != 0;
}
