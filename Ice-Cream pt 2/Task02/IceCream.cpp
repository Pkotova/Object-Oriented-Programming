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
		//destroy();
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
		destroy();
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
		<< "Price for ice cream: " << current.getPrice() <<"BGN"<< endl;

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
	return (i1.flavour != i2.flavour) ||
		(i1.balls != i2.balls) ||
		(strcmp(i1.name, i2.name) != 0);
}
IceCream& perfect(IceCream* all, int size,double pinMoney)
{
	int maxBalls = all[0].getBalls();
	double maxPrice = all[0].getPrice();
	IceCream current;
	
	for (int i = 0; i < size; i++)
	{
		if (all[i].getPrice() <= pinMoney)
		{
			current = all[i];
		}
		else if (all[i].getBalls() == maxBalls)
		{
			if (all[i].getPrice() >= current.getPrice())
			{
				current = all[i];
			}
		}
		else cout << "No such ice cream" << endl;
	}
	return current;
}
void findIceCream(IceCream* all, int size, IceCreamFlavour flavour)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(all[i].getFlavour().getFlavour(), flavour.getFlavour()) == 0)
		{
			cout << all[i] << endl;
		}
		else cout << "No such ice cream" << endl;
	}
}