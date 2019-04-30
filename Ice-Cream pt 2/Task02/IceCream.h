#pragma once
#include "IceCreamFlavour.h"
class IceCream
{
private:
	char* name;
	IceCreamFlavour flavour;
	int balls;		//how many balls

	void copy(const IceCream&);
	void destroy();

public:
	IceCream();
	IceCream(const IceCream&);
	IceCream& operator=(const IceCream&);
	IceCream(const char*, const IceCreamFlavour&, const int&);

	void setName(const char*);
	char* getName()const;
	void setFlavour(const IceCreamFlavour&);
	IceCreamFlavour& getFlavour();
	void setBalls(const int&);
	int getBalls()const;
	double getPrice();


	friend ostream& operator<<(ostream&, IceCream&);
	friend istream& operator>>(istream&, IceCream&);
	friend bool operator<(const IceCream&, const IceCream&);
	friend bool operator>(const IceCream&, const IceCream&);
	friend bool operator<=(const IceCream&, const IceCream&);
	friend bool operator==(const IceCream&, const IceCream&);
	friend bool operator>=(const IceCream&, const IceCream&);
	friend bool operator!=(const IceCream&, const IceCream&);

	~IceCream();
};

