#include "pch.h"
#include "House.h"
#include "Character.h"
#include<iostream>
#include<cstring>

void House::copy(const House& other)
{
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	strcpy_s(this->location, strlen(other.location) + 1, other.location);
	strcpy_s(this->houseWords, strlen(other.houseWords) + 1, other.houseWords);
	this->size = other.size;
	this->capacity = other.capacity;
	this->team = new Character*[this->capacity];
	for (int i = 0; i < size; i++)
	{
		team[i] = other.team[i]->clone();
	}
}

void House::destroy()
{
	delete[] this->name;
	delete[] this->location;
	delete[] this->houseWords;
	for (int i = 0; i < this->size; i++)
	{
		delete team[i];
	}
	delete[] team;
}
House::House() : House("Default","Default","Default")
{}

House::House(const House& other) 
{
	copy(other);
}

House::House(const char* name, const char* location, const char* houseWords)
	: name(nullptr), location(nullptr), houseWords(nullptr)
{
	setName(name);
	setLocation(location);
	setHouseWords(houseWords);
	this->size = 0;
	this->capacity = 10;
	this->team = new Character*[this->capacity];

}

House& House::operator=(const House& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

void House::setName(const char* _name)
{
	if (_name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}
}

void House::setLocation(const char* _location)
{
	if (_location != nullptr)
	{
		delete[] this->location;
		this->location = new char[strlen(_location) + 1];
		strcpy_s(this->location, strlen(_location) + 1, _location);
	}
}

void House::setHouseWords(const char* _houseWords)
{
	if (_houseWords != nullptr)
	{
		delete[] this->houseWords;
		this->houseWords = new char[strlen(_houseWords) + 1];
		strcpy_s(this->houseWords, strlen(_houseWords) + 1, _houseWords);
	}
}

char* House::getName()const
{
	return this->name;
}

char* House::getLocation()const
{
	return this->location;
}

char* House::getHouseWords()const
{
	return this->houseWords;
}

int House::getCapacity()const
{
	return this->capacity;
}

int House::getSize()const
{
	return this->size;
}

void House::resizeUp()
{
	this->capacity *= 2;
	Character** temp = new Character*[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = team[i]->clone();
	}
	delete[] team;
	team = temp;
}

void House::resizeDown()
{
	this->capacity /= 2;
	Character** temp = new Character*[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = team[i]->clone();
	}
	delete[] team;
	team = temp;
}

bool House::hasCharacter(const char* name)const
{
	for (int i = 0; i < this->size; i++)
	{
		if (strcmp(team[i]->getFullName(), name) == 0)
		{
			return true;
		}
	}
	return false;
}

bool House::isFull()const
{
	return (this->size == this->capacity);
}

void House::add(const Character& character)
{
	if (hasCharacter(character.getFullName())) 
	{
		return;
	}
	if (isFull())
	{
		resizeUp();
	}
	this->team[size++] = character.clone();
}

void House::remove(const Character& character)
{
	for (int i = 0; i < this->size; i++)
	{
		if (*(team[i]) == character)
		{
			delete team[i];
			team[i] = team[size--];
			if (this->size < (this->capacity / 2))
			{
				resizeDown();
			}
			break;
		}
	}
}

void House::srinkShow()const
{
	double chance = ((double)getTotalScore() / 10 > 100) ? 100 : (double)getTotalScore() / 10;
	std::cout << "| House: " << this->name << std::endl;
	std::cout << "----------------------------" << std::endl;
	for (int i = 0; i < this->size; i++)
	{
		team[i]->show();
	}
	std::cout << "Total score: " << getTotalScore() << std::endl;
	std::cout << "You chance to win the Game of Thrones is: : " << chance <<"%" << std::endl;
	std::cout << std::endl;
}

void House::showTeam()const
{
	double chance = ((double)getTotalScore() / 10 > 100) ? 100 : (double)getTotalScore() / 10;
	std::cout << "|House: " << this->name;
	std::cout << " |Location: " << this->location << std::endl;
	std::cout << "|House words: " << this->houseWords << std::endl;
	for (int i = 0; i < this->size; i++)
	{
		team[i]->print();
	}
	std::cout << "Total score: " << getTotalScore() << std::endl;
	std::cout << "You chance to win the Game of Thrones is: : " << chance << "%" << std::endl;
	std::cout << std::endl;
}

int House::getTotalScore()const
{
	int total = 0;
	for (int i = 0; i < this->size; i++)
	{
		total += this->team[i]->getScore();
	}
	return total;
}

void House::sort(bool(*comparator)(const Character & c1, const Character & c2))
{
	for (int i = 0; i < this->size - 1; i++)
	{
		for (int j = i + 1; j < this->size; j++)
		{
			if (comparator(*team[i],*team[j]))
			{
				std::swap(team[i], team[j]);
			}
		}
	}
}

Character & House::getExtreme(bool(*comparator)(const Character & c1, const Character & c2))
{
	Character* c = this->team[0];

	for (int i = 1; i < this->size; ++i)
	{
		if (comparator(*team[i], *c))
		{
			c = team[i];
		}
	}
	return *c;
}

House::~House()
{
	destroy();
}