#include "pch.h"
#include "Character.h"
#include<iostream>
#include<cstring>

Character::Character() : Character("Default",'m',123)
{}

Character::Character(const char* fullName, unsigned int age, char sex) : fullName(nullptr)
{
	setFullName(fullName);
	setAge(age);
	setSex(sex);
}

Character::Character(const Character& other) : Character(other.fullName,other.age,other.sex)
{}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		setFullName(other.fullName);
		setAge(other.age);
		setSex(other.sex);
	}
	return *this;
}

void Character::setFullName(const char* _fullName)
{
	if (_fullName != nullptr) {
		delete[] this->fullName;
		this->fullName = new char[strlen(_fullName) + 1];
		strcpy_s(this->fullName, strlen(_fullName) + 1,_fullName);
	}
}

void Character::setAge(int _age)
{
	if(_age >= 0) this->age = _age;
}

void Character::setSex(char _sex)
{
	if(_sex == 'm'|| _sex == 'f') this->sex = _sex;
}

char* Character::getFullName()const
{
	return this->fullName;
}

unsigned int Character::getAge()const
{
	return this->age;
}

char Character::getSex()const
{
	return this->sex;
}

int Character::getScore() const
{
	return 0;
}

void Character::show()const
{
	std::cout << "- " << this->fullName;
	std::cout << ", Age: " << this->age;
	std::cout << ", Score: " << getScore() << std::endl;
}

void Character::print() const
{
	std::cout << "- " << this->fullName << std::endl;
	std::cout << "- Age: " << this->age << std::endl;
	std::cout << "- Sex: " << this->sex << std::endl;
	std::cout << "- Score: " << getScore() << std::endl;
}

bool Character::operator==(const Character& other)const
{
	return strcmp(this->fullName, other.fullName) == 0;
}

Character::~Character()
{
	delete[] this->fullName;
}

