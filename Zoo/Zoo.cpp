#include "stdafx.h"
#include "Zoo.h"
#include"Animal.h"
#include<iostream>
#include<cstring>

void Zoo::copy(const Zoo& other)
{
	strcpy_s(this->location, strlen(other.location), other.location);
	this->size = other.size;
	this->capacity = other.capacity;
	this->animals = new Animal*[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->animals[i] = other.animals[i]->clone();
	}
}

void Zoo::destroy()
{
	delete[] location;
	for (int i = 0; i < this->size; i++)
	{
		delete this->animals[i];
	}
	delete[] animals;
}

Zoo::Zoo() : Zoo("Default")
{}

Zoo::Zoo(const Zoo& other)
{
	copy(other);
}

Zoo& Zoo::operator=(const Zoo& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

Zoo::Zoo(const char* location) : location(nullptr)
{
	this->size = 0;
	this->capacity = 10;
	this->animals = new Animal*[this->capacity];
	setLocation(location);
}

int Zoo::getSize()const
{
	return this->size;
}

int Zoo::getCapacity()const
{
	return this->capacity;
}

void Zoo::setLocation(const char* _location)
{
	if (_location != nullptr)
	{
		delete[] this->location;
		this->location = new char[strlen(_location) + 1];
		strcpy_s(this->location, strlen(_location) + 1, _location);
	}
}

char* Zoo::getLocation()const
{
	return this->location;
}

bool Zoo::isFull()const
{
	return (this->size == this->capacity);
}

void Zoo::addAnimal(const Animal& animal)
{
	if (isFull()) resizeUp();
	animals[size++] = animal.clone();
}

void Zoo::removeAnimal(const Animal& animal)
{
	for (int i = 0; i < size; ++i) 
	{
		if (*(animals[i]) == animal) 
		{
			delete animals[i];
			animals[i] = animals[size - 1];
			size--;
			if (size < capacity / 2)
			{
				resizeDown();
			}
			break;
		}
	}
}

void Zoo::showAnimals()const
{
	std::cout << "---------------------" << std::endl;
	std::cout << "| Zoo Location:" << this->location<< " |" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "| Ticket price: " << getTicketPrice() << std::endl;
	std::cout << "---------------------" << std::endl;
	for (int i = 0; i < this->size; i++)
	{
		std::cout << "- ";
		this->animals[i]->print();
		std::cout<<std::endl;
	}
}

double Zoo::getTicketPrice()const
{
	int rate = 0, endangered = 0;
	for (int i = 0; i < this->size; i++)
	{
		rate += this->animals[i]->getRating();
		if (this->animals[i]->getIsEndangered())
		{
			endangered++;
		}
	}
	return (this->size + (rate / this->size) + (0.1*endangered));
}

void Zoo::resizeUp()
{
	capacity *= 2;
	Animal** temp = new Animal*[capacity];
	for (int i = 0; i < size; ++i) 
	{
		temp[i] = animals[i];
	}
	delete[] animals;
	this->animals = temp;
}

void Zoo::resizeDown()
{
	capacity /= 2;
	Animal** temp = new Animal*[capacity];
	for (int i = 0; i < size; ++i)
	{
		temp[i] = animals[i];
	}
	delete[] animals;
	this->animals = temp;
}

Zoo::~Zoo()
{
	destroy();
}