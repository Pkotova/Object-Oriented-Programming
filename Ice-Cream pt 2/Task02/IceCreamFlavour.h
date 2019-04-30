#pragma once
#include<iostream>
using namespace std;
class IceCreamFlavour
{
private:
	char flavour[32];
	double price;
public:
	IceCreamFlavour();
	IceCreamFlavour(const IceCreamFlavour&);
	IceCreamFlavour& operator=(const IceCreamFlavour&);
	IceCreamFlavour(const char*, const double&);
	void setFlavour(const char*);
	char* getFlavour();
	void setPrice(const double&);
	double getPrice();

	friend ostream& operator<<(ostream&, const IceCreamFlavour&);
	friend istream& operator>>(istream&, IceCreamFlavour&);
	friend bool operator<(const IceCreamFlavour&, const IceCreamFlavour&);
	friend bool operator>(const IceCreamFlavour&, const IceCreamFlavour&);
	friend bool operator<=(const IceCreamFlavour&, const IceCreamFlavour&);
	friend bool operator==(const IceCreamFlavour&, const IceCreamFlavour&);
	friend bool operator>=(const IceCreamFlavour&, const IceCreamFlavour&);
	friend bool operator!=(const IceCreamFlavour&, const IceCreamFlavour&);
	//~IceCreamFlavour();
};

