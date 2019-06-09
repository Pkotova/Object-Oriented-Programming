#include "stdafx.h"
#include "Carnivore.h"
#include"Animal.h"
#include <iostream>

Carnivore::Carnivore() : Carnivore("Default", 0, 0, false,false)
{}

Carnivore::Carnivore(const char*species, int age, double food, bool isEndagered,bool isNocturnal) 
	:Animal(species,age,food, isEndagered)
{
	setisNocturnal(isNocturnal);
}

void Carnivore::setisNocturnal(bool _isNocturnal)
{
	this->isNocturnal = _isNocturnal;
}

bool Carnivore::getisNocturnal()const
{
	return this->isNocturnal;
}

double Carnivore::getFoodQuantity()const
{
	return ((this->food) + (0.5)*this->age);
}

int Carnivore::getRating() const
{	
	return  (getFoodQuantity() > 10) ? 7 : 5;
}

void Carnivore::print() const
{
	Animal::print();
	std::cout << "Is Nocturnal: " << std::boolalpha << this->isNocturnal << std::endl;
	std::cout << "---------------------" << std::endl;
}

Carnivore* Carnivore::clone() const
{
	return new Carnivore(*this);
}