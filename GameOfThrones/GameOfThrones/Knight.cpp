#include "pch.h"
#include "Knight.h"
#include"Character.h"
#include <iostream>
#include <cstring>

Knight::Knight() : Knight("Default",0,'m',"default",0)
{}

Knight::Knight(const char* fullName, unsigned int age, char sex, const char title[40], unsigned int numberOfKillings)
	: Character(fullName,age,sex)
{
	setTitle(title);
	setNumberOfKillings(numberOfKillings);
}

void Knight::setTitle(const char _title[40])
{
	if(_title != NULL) strcpy_s(this->title, strlen(_title) + 1, _title);
}

void Knight::setNumberOfKillings(unsigned int _numberOfKillings)
{
	if(_numberOfKillings >= 0)this->numberOfKillings = _numberOfKillings;
}

char* Knight::getTitle()
{
	return this->title;
}

unsigned int Knight::getNumberOfKillings()const
{
	return this->numberOfKillings;
}

int Knight::getScore()const
{
	return this->numberOfKillings * 10;
}

Knight* Knight::clone()const
{
	return new Knight(*this);
}

void Knight::print()const
{
	std::cout << std::endl;
	std::cout << "	 KNIGHT: " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout <<"- "<<this->title <<" " << this->fullName << std::endl;
	std::cout << "- Age: " << this->age << std::endl;
	std::cout << "- Sex: " << this->sex << std::endl;
	std::cout << "- Score: " << getScore() << std::endl;
	std::cout << "-   Title: " << this->title << std::endl;
	std::cout << "-   Number of Killings : " << this->numberOfKillings << std::endl;
}
