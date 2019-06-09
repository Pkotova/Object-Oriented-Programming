#include "pch.h"
#include "File.h"
#include<iostream>
using namespace std;


File::File() : File("default")
{}
File::File(const File& other) : File(other.name)
{}
File& File::operator=(const File& other)
{
	if (this != &other)
	{
		setName(other.name);
	}
	return *this;
}
File::File(const char* name) : name(nullptr)
{
	setName(name);
}
void File::setName(const char* _name)
{
	if (_name != nullptr)
	{
		delete[] name;
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}
}
char* File::getName()const
{
	return this->name;
}
void File::print()const
{
	cout << "Name: " << this->name << endl;
}


File::~File()
{
}
