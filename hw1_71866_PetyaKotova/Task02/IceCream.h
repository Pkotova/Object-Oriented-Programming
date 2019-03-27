#pragma once
#include "IceCreamFlavour.h"

class IceCream
{
private:

	IceCreamFlavour flavour;
	int balls;
	char* name;

public:

	IceCream(const IceCreamFlavour& = IceCreamFlavour(), const int& = 0, const char* = " default ice cream");
	IceCream(const IceCream& other);
	IceCream& operator=(const IceCream& other);
	~IceCream();
	
	void setFlavour(const IceCreamFlavour&);
	IceCreamFlavour getFlavour() const;
	void setBalls(const int&);
	int getBalls() const;
	void setName(const char*);
	const char* getName() const;

	double getPrice() const; // calculating price of an ice cream (amount of ball * price for each ball)
	//const because it does not change data 
	void create();
	void print() const;
};