#include "pch.h"
#include "Ruler.h"
#include "Character.h"
#include<iostream>

Ruler::Ruler() :Ruler("Default", 0, 'm', 0, false)
{}

Ruler::Ruler(const char* name, unsigned int age, char sex ,unsigned int numberOfChildren, bool hasSat)
	: Character(name, age, sex)
{
	setNumberOfChildren(numberOfChildren);
	SethasSat(hasSat);
}

void Ruler::setNumberOfChildren(unsigned int _numberOfChildren)
{
	this->numberOfChildren = _numberOfChildren;
}

void Ruler::SethasSat(bool hasSat)
{
	this->hasSat = hasSat;
}

unsigned int Ruler::getNumberOfChildren() const
{
	return this->numberOfChildren;
}

bool Ruler::getHasSat() const
{
	return this->hasSat;
}

int Ruler::getScore() const
{
	return (this->hasSat) ? (this->numberOfChildren * 10) : this->numberOfChildren;
}

Ruler* Ruler::clone()const
{
	return new Ruler(*this);
}

void Ruler::print()const
{
	std::cout << std::endl;
	std::cout << "	RULER:" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "- " << this->fullName << std::endl;
	std::cout << "- Age: " << this->age << std::endl;
	std::cout << "- Sex: " << this->sex << std::endl;
	std::cout << "- Score: " << getScore() << std::endl;
	std::cout << "-	  Number of Children: " << this->numberOfChildren << std::endl;
	std::cout << "-	  Has sat on the Iron Throne: " << this->hasSat << std::endl;
}

