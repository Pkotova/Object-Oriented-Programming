#include "pch.h"
#include "IceCream.h"

void IceCream::copy(const IceCream& other)
{
	setName(other.name);
	setFlavour(other.flavour);
	setBalls(other.balls);
}
void IceCream::destroy()
{
	delete[] this->name;
}
IceCream::IceCream() : name(nullptr)
{
	setName("default");
	this->flavour = IceCreamFlavour();
	setBalls(0);
}
IceCream::IceCream(const IceCream& other)
{
	copy(other);
}
IceCream& IceCream::operator=(const IceCream& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}
IceCream::~IceCream()
{
	destroy();
}
IceCream::IceCream(const char* newName, const IceCreamFlavour& newFlavour, const int& newBalls) : name(nullptr)
{
	setName(newName);
	setFlavour(newFlavour);
	setBalls(newBalls);
}
void IceCream::setName(const char* newName)
{
	if (newName != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}
char* IceCream::getName()const
{
	return this->name;
}
void IceCream::setFlavour(const IceCreamFlavour& newFlavour)
{
	this->flavour = newFlavour;
}
IceCreamFlavour& IceCream::getFlavour()
{
	return this->flavour;
}
void IceCream::setBalls(const int& newBalls)
{
	this->balls = newBalls;
}
int IceCream::getBalls()const
{
	return this->balls;
}
double IceCream::getPrice()
{
	return (this->balls * flavour.getPrice());
}
ostream& operator<<(ostream& out, IceCream& current)
{
	out << "Name: " << current.name << endl
		<< "Flavour: " << current.flavour
		<< "Balls: " << current.balls << endl
		<< "Price for ice cream: " << current.getPrice() << endl;

	return out;
}
istream& operator>>(istream& in, IceCream& current)
{
	cout << "Name: ";
	in >> current.name;
	cout << "Flavour: " << endl;
	in >> current.flavour;
	cout << "Amount of balls: ";
	in >> current.balls;

	return in;
}
bool operator<(const IceCream& i1, const IceCream& i2)
{
	return (i1.flavour < i2.flavour) &&
		(i1.balls < i2.balls) &&
		(strcmp(i1.name, i2.name) < 0);

}
bool operator<=(const IceCream& i1, const IceCream& i2)
{
	return (i1.flavour <= i2.flavour) &&
		(i1.balls <= i2.balls) &&
		(strcmp(i1.name, i2.name) <= 0);
}
bool operator>(const IceCream& i1, const IceCream& i2)
{
	return (i1.flavour > i2.flavour) &&
		(i1.balls > i2.balls) &&
		(strcmp(i1.name, i2.name) > 0);
}
bool operator>=(const IceCream& i1, const IceCream& i2)
{
	return (i1.flavour >= i2.flavour) &&
		(i1.balls >= i2.balls) &&
		(strcmp(i1.name, i2.name) >= 0);
}
bool operator==(const IceCream& i1, const IceCream& i2)
{
	return (i1.flavour == i2.flavour) &&
		(i1.balls == i2.balls) &&
		(strcmp(i1.name, i2.name) == 0);
}
bool operator!=(const IceCream& i1, const IceCream& i2)
{
	return (i1.flavour != i2.flavour) &&
		(i1.balls != i2.balls) &&
		(strcmp(i1.name, i2.name) != 0);
}