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
	if ((double)this->size < temp)
	{
		this->capacity /= 2;
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
	this->capacity = 4;
	this->iceCreams = new IceCream[4];
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
}
ostream& operator<<(ostream& out, const IceCreamContainer& current)
{
	cout << "All Ice Creams in the container: " << endl;
	for (int i = 0; i < current.size; i++)
	{
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
