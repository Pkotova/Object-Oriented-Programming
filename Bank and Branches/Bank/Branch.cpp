#include "Branch.h"
#include <cstring>

char * Branch::getLocation() const
{
	return this->location;
}

int Branch::getId() const
{
	return this->id;
}

int Branch::getWorkCoeff() const
{
	return this->workCoeff;
}

void Branch::setLocation(const char * location)
{
	if (location != NULL) {
		delete[] this->location;
		this->location = new char[strlen(location) + 1];
		strcpy(this->location, location);
	}
}

void Branch::setId(const int & id)
{
	if (id >= 0) this->id = id;
}

void Branch::setWorkCoeff(const int & workCoeff)
{
	this->workCoeff = workCoeff;
}

Branch::Branch() : location(NULL)
{
	setLocation("Sofia");
	setId(0);
	setWorkCoeff(0);
}

Branch::Branch(const char *location , const int & id, const int & workCoeff) : location(NULL)
{
	setLocation(location);
	setId(id);
	setWorkCoeff(workCoeff);
}

Branch::Branch(const Branch & other) : Branch(other.location,other.id,other.workCoeff)
{
}

Branch & Branch::operator=(const Branch & other)
{
	if (this != &other) {
		this->setLocation(other.location);
		this->setId(other.id);
		this->setWorkCoeff(other.workCoeff);
	}
	return *this;
}

Branch & Branch::operator++()
{
	this->workCoeff++;
	return *this;
}

Branch & Branch::operator++(int)
{
	this->workCoeff++;
	return *this;
}

Branch::~Branch()
{
	delete[] this->location;
}

