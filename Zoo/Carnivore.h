#pragma once
#include"Animal.h"
class Carnivore : public Animal
{
private:

	bool isNocturnal;

public:
	Carnivore();
	Carnivore(const char*, int, double, bool,bool);

	void setisNocturnal(bool);
	bool getisNocturnal()const;

	double getFoodQuantity()const;
    int getRating() const;
    void print() const;

	Carnivore* clone() const;
};