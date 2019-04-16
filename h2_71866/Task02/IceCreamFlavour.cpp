#include "pch.h"
#include "IceCreamFlavour.h"
#include<iostream>
#include<cstring>

using namespace std;

IceCreamFlavour::IceCreamFlavour()
{
	strcpy_s(this->flavour, 9, "default");
	this->price = 0.0;
}
IceCreamFlavour::IceCreamFlavour(const IceCreamFlavour& other)
{
	setFlavour(other.flavour);
	setPrice(other.price);
}
IceCreamFlavour& IceCreamFlavour ::operator=(const IceCreamFlavour& other)
{
	if (this != &other)
	{
		setFlavour(other.flavour);
		setPrice(other.price);
	}
	return *this;
}
IceCreamFlavour::IceCreamFlavour(const char* newFlavour, const double& newPrice)
{
	setFlavour(newFlavour);
	setPrice(newPrice);
}

void IceCreamFlavour::setFlavour(const char* newFlavour)
{
	strcpy_s(this->flavour, strlen(newFlavour) + 1, newFlavour);
}
char* IceCreamFlavour::getFlavour()
{
	return this->flavour;
}
void IceCreamFlavour::setPrice(const double& newPrice)
{
	this->price = newPrice;
}
double IceCreamFlavour::getPrice()
{
	return this->price;
}
ostream& operator<<(ostream& out, const IceCreamFlavour& current)
{
	cout << endl;
	out << "   - Flavour: " << current.flavour << endl;
	out << "   - Price per ball: " << current.price <<"BGN"<< endl;

	return out;
}
istream& operator>>(istream& in, IceCreamFlavour& current)
{
	cout << "Your Flavour: " << endl;
	cout << "Flavour: ";
	in >> current.flavour;
	cout << "Price per ball: ";
	in >> current.price;
	return in;
}
bool operator<(const IceCreamFlavour& f1, const IceCreamFlavour& f2)
{
	return (strcmp(f1.flavour, f2.flavour) < 0) && (f1.price < f1.price);
}
bool operator<=(const IceCreamFlavour& f1, const IceCreamFlavour& f2)
{
	return (strcmp(f1.flavour, f2.flavour) <= 0) && (f1.price <= f1.price);
}
bool operator>(const IceCreamFlavour& f1, const IceCreamFlavour& f2)
{
	return (strcmp(f1.flavour, f2.flavour) > 0) && (f1.price > f1.price);
}
bool operator>=(const IceCreamFlavour& f1, const IceCreamFlavour& f2)
{
	return (strcmp(f1.flavour, f2.flavour) >= 0) && (f1.price >= f1.price);
}
bool operator==(const IceCreamFlavour& f1, const IceCreamFlavour& f2)
{
	return (strcmp(f1.flavour, f2.flavour) == 0) && (f1.price == f1.price);
}
bool operator!=(const IceCreamFlavour& f1,const IceCreamFlavour& f2)
{
	return ((strcmp(f1.flavour, f2.flavour) != 0) || (f1.price != f1.price));
}
