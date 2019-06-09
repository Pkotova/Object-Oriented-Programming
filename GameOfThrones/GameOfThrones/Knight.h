#pragma once
#include "Character.h"
class Knight : public Character
{
private:

	char title[40];
	unsigned int numberOfKillings;

public:
	Knight();
	Knight(const char*, unsigned int, const char,const char[40], unsigned int);

	void setTitle(const char[40]);
	void setNumberOfKillings(unsigned int);

	char* getTitle();
	unsigned int getNumberOfKillings()const;

	Knight* clone() const;
	int getScore()const;
	void print()const;
};

