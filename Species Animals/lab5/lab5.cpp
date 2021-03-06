// lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

enum type 
{
	safe,
	endangered,
	extinct
};
struct Species
{
	char* name;
	int age;
	type typeOfAnimal;

	Species(char* name, int age, type type);
};

Species::Species(char* name, int age, type type)
{
	strcpy_s(this->name, strlen(name) + 1, "mammal");
	age = 20;
	type = safe;
}
class Animal
{
public:
	Animal();
	Animal(const char*, int, Species);
	Animal(const Animal&);
	Animal& operator = (const Animal&);
	~Animal();
	void setName(const char*);
	const char* getName() const;
	void setAge(int);
	int getAge() const;
	void setSpecies(Species);
	Species getSpecies() const;
private:
	char * name;
	int age;
	Species species;
};
Animal::Animal() : Animal("bear",10,)
{

}
Animal::Animal(const char* newName, int newAge, Species newSpecies) : name(NULL)
{
	setName(newName);
	setAge(newAge);
	setSpecies(newSpecies);
}
Animal::Animal(const Animal& other) : name(NULL)
{
	setName(other.name);
	setAge(other.age);
	setSpecies(other.species);
}
Animal & Animal :: operator = (const Animal& other)
{
	if (this != &other)
	{
		setName(other.name);
		setAge(other.age);
		setSpecies(other.species);
	}
	return *this;
}
Animal::~Animal()
{
	delete [] name;
}
void Animal::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
const char* Animal::getName() const
{
	return name;
}
void Animal::setAge(int age)
{
	this->age = age;
}
int Animal::getAge() const
{
	return age;
}
void Animal::setSpecies(Species species)
{
	this->species = species;
}
 Species Animal::getSpecies() const
{
	return species;
}
int main()
{
    return 0;
}

