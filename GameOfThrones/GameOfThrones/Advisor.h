#pragma once
#include "Character.h"
class Advisor : public Character
{
private:

	bool isMaester;
	bool isHand;

public:
	Advisor();
	Advisor(const char*, unsigned int, char, bool, bool);

	void setIsMaister(bool);
	void setIsHand(bool);

	bool getIsMaister()const;
	bool getIsHand()const;

	Advisor* clone()const;
	int getScore()const;
	void print()const;
};

