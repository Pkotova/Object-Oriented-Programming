#include "pch.h"
#include "IceCreamContainer.h"


void IceCreamContainer::copy(const IceCreamContainer& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->iceCreams = new IceCream[capacity];
	for (int i = 0; i < other.size; i++)
	{
		this->iceCreams[i] = other.iceCreams[i];
	}
}
void IceCreamContainer::destroy()
{
	delete[] this->iceCreams;
}
void IceCreamContainer::resizeUp()
{
	this->capacity *= 2;
	IceCream* temp = new IceCream[capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->iceCreams[i];
	}
	destroy();
	this->iceCreams = temp;
}
void IceCreamContainer::resizeDown()
{
	double temp = (this->capacity * 0.75);
	if (this->size < temp)
	{
		this->capacity -=2; // намаля capacity? не е указано с колко
		IceCream * temp = new IceCream[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = this->iceCreams[i];
		}
		destroy();
		this->iceCreams = temp;
	}
}
IceCreamContainer::IceCreamContainer()
{
	this->size = 0;
	this->capacity = 8;
	this->iceCreams = new IceCream[this->capacity];
}
IceCreamContainer::IceCreamContainer(const IceCreamContainer& other)
{
	copy(other);
}
IceCreamContainer::IceCreamContainer(IceCream* newIceCreams, const int& newSize, const int& newCapacity)
{
	this->iceCreams = newIceCreams;
	this->size = newSize;
	this->capacity = newCapacity;
}
IceCreamContainer& IceCreamContainer::operator=(const IceCreamContainer& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}
void IceCreamContainer::setSize(const int& newSize)
{
	this->size = newSize;
}
int IceCreamContainer::getSize()const
{
	return this->size;
}
void IceCreamContainer::setCapacity(const int& newCapacity)
{
	this->capacity = newCapacity;
}
int IceCreamContainer::getCapacity()const
{
	return this->capacity;
}
IceCream* IceCreamContainer::getIceCreams()const
{
	return this->iceCreams;
}
void IceCreamContainer::add(const IceCream& current)
{
	if (size == capacity)
	{
		resizeUp();
	}
	this->iceCreams[size] = current;
	size++;
	resizeDown();
}
void IceCreamContainer::remove(const int& index)
{
	if (index < 0 || index > size - 1)
		return;
	for (int i = index; i < size - 1; ++i)
	{
		iceCreams[i] = iceCreams[i + 1];
	}
	size--;
	resizeDown();
}
ostream& operator<<(ostream& out, const IceCreamContainer& current)
{
	cout << endl;
	cout << "All Ice Creams in the container: " << endl;
	for (int i = 0; i < current.size; i++)
	{
		cout << "#" << i + 1<<"| ";
		cout << "------------------" << endl;
		out << current.iceCreams[i] << endl;
	}
	return out;
}
istream& operator>>(istream& in, IceCreamContainer& current)
{
	cout << "Create your container: " << endl;
	for (int i = 0; i < current.size; i++)
	{
		in >> current.iceCreams[i];
	}
	return in;
}
IceCreamContainer::~IceCreamContainer()
{
	destroy();
}
bool IceCreamContainer::has(const IceCream& icecream)
{
	bool result = false;
	for (int i = 0; i < this->getSize(); i++)
	{
		if (this->iceCreams[i] == icecream)
		{
			result = true;
		}
	}
	return result;
}
double IceCreamContainer::report()
{
	double money = 0;
	for (int i = 0; i < this->getSize(); i++)
	{
		money += (this->iceCreams[i].getPrice());
	}
	return money;
}