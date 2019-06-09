#pragma once
#include"Character.h"
class Ruler : public Character
{
private:

	unsigned int numberOfChildren;
	bool hasSat; // has sat on the Iron Throne

public:
	Ruler();
	Ruler(const char*, unsigned int, char, unsigned int, bool);
	
	void setNumberOfChildren(unsigned int);
	void SethasSat(bool);
	 
	unsigned int getNumberOfChildren()const;
	bool getHasSat()const;
	
	Ruler* clone()const;
	int getScore()const;
	void print()const;
};

