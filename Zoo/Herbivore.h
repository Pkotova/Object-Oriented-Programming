#pragma once
#include"Animal.h"
class Herbivore : public Animal
{
private:

	bool isTamed;

public:
	Herbivore();
	Herbivore(const char*, int, double, bool,bool);

	void setIsTamed(bool);
	bool getIsTamed()const;

	double getFoodQuantity()const;
	int getRating() const;
	void print() const;

	Herbivore* clone() const;
};