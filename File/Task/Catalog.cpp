#include "pch.h"
#include "Catalog.h"
#include "File.h"
#include <iostream>
#include <cstring>

using namespace std;

void Catalog::copy(const Catalog& other)
{
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->length = other.length;
	this->capacity = other.capacity;
	this->files = new File*[this->capacity];
	for (int i = 0; i < this->length; i++)
	{
		this->files[i] = other.files[i]->clone();
	}
}
void Catalog::destroy()
{
	for (int i = 0; i < this->length; i++)
	{
		delete this->files[i];
	}
	delete[] this->files;
}
Catalog::Catalog() : Catalog("Default")
{}
Catalog::Catalog(const Catalog& other)
{
	copy(other);

}
Catalog::Catalog(const char* name)
{
	setName(name);
	this->length = 0;
	this->capacity = 20;
	this->files = new File*[this->capacity];
	
}
Catalog& Catalog::operator=(const Catalog& other)
{
	if (this != &other)
	{
		File::operator=(other);
		destroy();
		copy(other);
	}
	return *this;
}
int Catalog::size()const 
{
	int total = 0;
	for (int i = 0; i < this->length; i++)
	{
		total += this->files[i]->size();
	}
	return total;
}
void Catalog::print()const
{
	cout << endl;
	cout << "Catalog name: ";
	File::print();
	for (int i = 0; i < this->length; i++)
	{
		this->files[i]->print();
	}
}

void Catalog::resizeUp()
{
	this->capacity *= 2;
	File** temp = new File*[this->capacity];
	for (int i = 0; i < this->length; i++)
	{
		temp[i] = this->files[i];
	}
	delete[] files;
	this->files = temp;
}
bool Catalog::isFull()const
{
	return (this->capacity == this->length);
}
void Catalog::addFile(const File& file)
{
	if (isFull()) resizeUp();
	this->files[length++] = file.clone();
}

Catalog* Catalog::clone()const
{
	return new Catalog(*this);
}
Catalog::~Catalog()
{
	destroy();
}
