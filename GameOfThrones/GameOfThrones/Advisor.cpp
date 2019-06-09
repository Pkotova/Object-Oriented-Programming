#include "pch.h"
#include "Advisor.h"
#include"Character.h"
#include <iostream>
#include <cstring>

Advisor::Advisor() : Advisor("Default",0,'m',false,false)
{}

Advisor::Advisor(const char* fullName, unsigned int age, char sex, bool isMaester, bool isHand)
		: Character(fullName, age, sex)
{
	setIsMaister(isMaester);
	setIsHand(isHand);
}

void Advisor::setIsHand(bool _isHand)
{
	this->isHand = _isHand;
}

void Advisor::setIsMaister(bool _isMaester)
{
	this->isMaester = _isMaester;
}

bool Advisor::getIsMaister() const
{
	return this->isMaester;
}

bool Advisor::getIsHand() const
{
	return this->isHand;
}

int Advisor::getScore()const
{
	return (this->isHand && this->isMaester) ? 50 : 25;
}

Advisor* Advisor::clone()const
{
	return new Advisor(*this);
}

void Advisor::print()const
{
	std::cout << std::endl;
	std::cout <<"	ADVISOR: " << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "- " << this->fullName << std::endl;
	std::cout << "- Age: " << this->age << std::endl;
	std::cout << "- Sex: " << this->sex << std::endl;
	std::cout << "- Score: " << getScore() << std::endl;
	std::cout << "-	 Is hand: "<<std::boolalpha <<this->isHand << std::endl;
	std::cout << "-	 Is maester: " << std::boolalpha << this->isMaester << std::endl;
}





