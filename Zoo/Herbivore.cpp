#include "stdafx.h"
#include "Herbivore.h"
#include "Animal.h"
#include<iostream>

Herbivore::Herbivore() : Herbivore("Default", 0, 0, false, false)
{}

Herbivore::Herbivore(const char*species, int age, double food, bool isEndagered, bool isTamed)
	:Animal(species, age, food, isEndagered)
{
	setIsTamed(isTamed);
}

void Herbivore::setIsTamed(bool _isTamed)
{
	this->isTamed = _isTamed;
}

bool Herbivore::getIsTamed()const
{
	return this->isTamed;
}

double Herbivore::getFoodQuantity()const
{
	return (isEndangered) ? (getFoodQuantity() + 1 + 0.2*this->age) : this->food;
}

int Herbivore::getRating() const
{
	return (isTamed) ? 4 : 5;
}

void Herbivore::print() const
{
	Animal::print();
	std::cout << "Is Tamed: " << std::boolalpha << this->isTamed << std::endl;
	std::cout << "---------------------" << std::endl;
}

Herbivore* Herbivore::clone() const
{
	return new Herbivore(*this);
}