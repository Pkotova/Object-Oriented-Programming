#include "stdafx.h"
#include "Animal.h"
#include<iostream>
#include<cstring>

Animal::Animal() : Animal("Default",0,0,false)
{}

Animal::Animal(const Animal& other) : Animal(other.species, other.age, other.food, other.isEndangered)
{}

Animal::Animal(const char* species, int age, double food, bool isEndangered) : species(nullptr)
{
	setSpecies(species);
	setAge(age);
	setFood(food);
	setIsEndangered(isEndangered);
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		//delete[] species;
		setSpecies(other.species);
		setAge(other.age);
		setFood(other.food);
		setIsEndangered(other.isEndangered);
	}
	return *this;
}

void Animal::setSpecies(const char*_species)
{
	if (_species != nullptr)
	{
		delete[] this->species;
		this->species = new char[strlen(_species) + 1];
		strcpy_s(this->species, strlen(_species) + 1, _species);
	}
}

void Animal::setAge(int _age)
{
	this->age = _age;
}

void Animal::setFood(double _food)
{
	this->food = _food;
}

void Animal::setIsEndangered(bool _isEndangered)
{
	this->isEndangered = _isEndangered;
}

char* Animal::getSpecies()const
{
	return this->species;
}

int Animal::getAge()const
{
	return this->age;
}

double Animal::getFood()const
{
	return this->food;
}

bool Animal::getIsEndangered()const
{
	return this->isEndangered;
}

int Animal::getRating()const
{
	return  (this->isEndangered || this->age < 5) ? 5 * 2 : 5;
}

void Animal::print()const
{
	std::cout << "Species: " << this->species << std::endl;
	std::cout << "Age: " << this->age << std::endl;
	std::cout << "Food: " << this->food << std::endl;
	std::cout << "Is Endangered: " <<std::boolalpha<<this->isEndangered << std::endl;
	std::cout << "Rating: " << getRating() << std::endl;
	std::cout << "Food Quantity: " << getFoodQuantity() << std::endl;;
}

bool Animal::operator==(const Animal& other)const
{
	return (strcmp(this->species, other.species) == 0);
}

Animal::~Animal()
{
	delete[] this->species;
}