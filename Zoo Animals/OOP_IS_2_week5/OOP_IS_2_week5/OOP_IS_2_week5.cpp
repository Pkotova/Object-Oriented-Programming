// OOP_IS_2_week5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstring>
enum status {safe,endangered,extinct};
struct species {
private:
	char* name;
	int age;
	status stat;
public:
	void setName(char* name) {
		if (name != nullptr) {
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
	}
	species(char* name = nullptr, int age = 25, status stat = safe) : name(nullptr) {
		setName(name);
		this->age = age;
		this->stat = stat;
	}
	species(const species& other) : species(other.name,other.age,other.stat)
	{}

	species& operator=(const species& other) {
		if (this != &other) {
			this->setName(other.name);
			this->age = other.age;
			this->stat = other.stat;
		}
	}
	~species() {
		delete[] this->name;
	}
};

class Animal {
private:
	char* name;
	int age;
	species specie;
public:
	void setName(const char*);
	void setAge(const int&);
	void setSpecies(const species&);

	void print() const;
	char* getName() const;
	int getAge() const;
	species getSpecies() const;

	Animal(const char* = nullptr, const int& = 1, const species& = species());
	Animal(const Animal&);
	Animal& operator=(const Animal&);

	~Animal();
};

void Animal::setName(const char * name)
{
	if (name != nullptr) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

void Animal::setAge(const int & age)
{
	this->age = age;
}

void Animal::setSpecies(const species & specie)
{
	this->specie = specie;
}


char * Animal::getName() const
{
	return this->name;
}

int Animal::getAge() const
{
	return this->age;
}

species Animal::getSpecies() const
{
	return this->specie;
}

Animal::Animal(const char *name, const int & age, const species& specie) : name(nullptr)
{
	this->setName(name);
	this->setAge(age);
	this->setSpecies(specie);
}

Animal::Animal(const Animal & other) : Animal(other.name,other.age,other.specie)
{
}

Animal & Animal::operator=(const Animal & other)
{
	this->setName(other.name);
	this->setAge(other.age);
	this->setSpecies(other.specie);
}

Animal::~Animal()
{
	delete[] this->name;
}


void main() {
	Animal a;
	Animal a2("Peter", 23, species("Otter", 10, safe));

}