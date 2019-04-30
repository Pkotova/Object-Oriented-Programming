#include "stdafx.h"
#include "Fisherman.h"


void Fisherman::copy(const Fisherman& other)
{
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->caughtFish = other.caughtFish;
	this->size = other.size;
	this->capacity = other.capacity;
}
void Fisherman::destroy()
{
	delete[] this->name;
	delete[] this->caughtFish;
}
void Fisherman::resize()
{
	this->capacity *= 2;
	Fish* temp = new Fish[capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = this->caughtFish[i];
	}
	destroy();
	this->caughtFish = temp;
}
Fisherman::Fisherman() : name(nullptr)
{
	setName("Default");
	this->size = 0;
	this->capacity = 8;
	this->caughtFish = new Fish[this->capacity];
}
Fisherman::Fisherman(const Fisherman& other)
{
	copy(other);
}
Fisherman& Fisherman::operator=(const Fisherman& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}
Fisherman::Fisherman(const char* newName, Fish* newCaughtFish, const int& newSize, const int& newCapacity) : name(nullptr)
{
	strcpy_s(this->name, strlen(newName) + 1, newName);
	this->caughtFish = newCaughtFish;
	this->size = newSize;
	this->capacity = newCapacity;
}
Fisherman::~Fisherman()
{
	destroy();
}

void Fisherman::setName(const char* newName)
{
	if (newName != nullptr)
	{
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}
char* Fisherman::getName()const
{
	return this->name;
}
/*
Fish* Fisherman::getCaughtFish()const
{
	for (int i = 0; i < this->size; i++)
	{
		 temp[i] = caughtFish[i];
	}
	return temp;
}
*/
void Fisherman::setSize(const int& newSize)
{
	this->size = newSize;
}
int  Fisherman::getSize()const
{
	return this->size;
}

void Fisherman::setCapacity(const int& newCapacity)
{
	this->capacity = newCapacity;
}
int Fisherman::getCapacity()const
{
	return this->capacity;
}

void Fisherman::addFish(const Fish& newFish)
{
	if (size == capacity)
	{
		resize();
	}
	this->caughtFish[size] = newFish;
	size++;
}
Fish Fisherman::biggestFish()
{
	Fish biggest = this->caughtFish[0];
	for (int i = 0; i < this->size; i++)
	{
		if (biggest.getWeight() < this->caughtFish[i].getWeight())
		{
			biggest = this->caughtFish[i];
		}
	}
	return biggest;
}
double Fisherman::report()
{
	double report = 0.0;
	for (int i = 0; i < this->size; i++)
	{
		report += (this->caughtFish[i].getPrice() * this->caughtFish[i].getWeight());
	}
	return report;
}

Fisherman& compareTo(Fisherman& fm1, Fisherman& fm2)
{
	return (fm1.report() > fm2.report()) ? fm1 : fm2;
}

ostream& operator<<(ostream& out , const Fisherman& f)
{
	out << "Name: " << f.name << endl
		<<"Caught Fish:" << endl;
	for (int i = 0; i < f.size; i++)
	{
		cout << "#" << i + 1 << "fish" << endl;
		cout << f.caughtFish[i];
	}
	return out;

}
