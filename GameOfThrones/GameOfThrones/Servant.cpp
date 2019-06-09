#include "pch.h"
#include "Servant.h"
#include "Character.h"
#include<iostream>

Servant::Servant() : Servant("Default",0,'m',false)
{}

Servant::Servant(const char* fullName, unsigned int age, char sex, bool isBetrayer)
	: Character(fullName, age, sex)
{
	setIsBetrayer(isBetrayer);
}

void Servant::setIsBetrayer(bool _isBetrayer)
{
	this->isBetrayer = _isBetrayer;
}

bool Servant::getIsBetrayer()const
{
	return this->isBetrayer;
}

int Servant::getScore() const
{
	 return (this->isBetrayer) ? 0 : 10;
}

Servant* Servant::clone()const
{
	return new Servant(*this);
}

void Servant::print()const
{
	std::cout << std::endl;
	std::cout << "	SERVANT:" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "- " << this->fullName << std::endl;
	std::cout << "- Age: " << this->age << std::endl;
	std::cout << "- Sex: " << this->sex << std::endl;
	std::cout << "- Score: " << getScore() << std::endl;
	std::cout << "-   Is Betrayer: " << this->isBetrayer << std::endl;
}
