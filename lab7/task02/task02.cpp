// task02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Branch;
class Bank
{
private:
	Branch* branches;
public:
	Bank & operator=(const Branch&);
	double avrgCoef(const Branch&);
};


class Branch
{
private:
	int id;
	char* location;
	double coef;
public:
	Branch(const int& id = 0, const char* = "default", const double& = 0.0);
	Branch(const Branch&);
	Branch& operator=(const Branch&);

	~Branch();

	void setId(int);
	void setLocation(const char*);
	void setCoef(double);

	int getId()const;
	const char* getLocation()const;
	double getCoef()const;
};
Branch::Branch(const int& id, const char* location, const double& coef) 
	: location(nullptr)
{
	setId(id);
	setLocation(location);
	setCoef(coef);
}
Branch::Branch(const Branch& other) 
	: Branch(other.id,other.location,other.coef){}

Branch& Branch::operator= (const Branch& other)
{
	if (this != &other)
	{
		setId(other.id);
		setLocation(other.location);
		setCoef(other.coef);
	}
	return *this;
}
void Branch::setId(int id)
{
	this->id = id;
}
void Branch::setLocation(const char* location)
{
	if (location != nullptr)
	{
		delete[] this->location;
		this->location = new char[strlen(location) + 1];
		strcpy_s(this->location, strlen(location) + 1, location);
	}
}
void Branch::setCoef(double coef)
{
	this->coef = coef;
}
int Branch::getId()const
{
	return this->id;
}
const char* Branch::getLocation()const
{
	return this->location;
}
double Branch::getCoef()const
{
	return this->coef;
}

Branch::~Branch()
{
	delete[] this->location; //delete using data
}
int main()
{
    return 0;
}

