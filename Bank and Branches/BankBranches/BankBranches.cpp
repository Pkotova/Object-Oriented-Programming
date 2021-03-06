// BankBranches.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Branch
{
private:
	int id;
	char* location;
	int coef;

	void copy(const Branch&);
	//void destroy();
public:
	Branch();
	Branch(const Branch&);
	Branch& operator=(const Branch&);
	~Branch();

	Branch(const int& id, const char*, const int&);
	void setId(const int&);
	int getId()const;
	void setLocation(const char*);
	char* getLocation()const;
	void setCoef(const int&);
	int getCoef()const;

	Branch& operator++();
	friend ostream& operator<<(ostream&,const Branch&);

};
Branch::Branch() : location(nullptr)
{
	setId(0);
	setLocation("Default");
	setCoef(10);
}
Branch::Branch(const Branch& other)
{
	copy(other);
}
Branch::Branch(const int& newId, const char* newLocation, const int& newCoef) : location(nullptr)
{
	setId(newId);
	setLocation(newLocation);
	setCoef(newCoef);
}
Branch& Branch::operator=(const Branch& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
Branch::~Branch()
{
	delete[] this->location;
}
void Branch::setId(const int& newId)
{
	this->id = newId;
}
int Branch::getId()const
{
	return this->id;
}
void Branch::setLocation(const char* newLocation)
{
	if (newLocation != nullptr)
	{
		delete[] this->location;
		this->location = new char[strlen(newLocation) + 1];
		strcpy_s(this->location, strlen(newLocation) + 1, newLocation);
	}
}
char* Branch::getLocation()const
{
	return this->location;
}
void Branch::setCoef(const int& newCoef)
{
	this->coef = newCoef;
}
int Branch::getCoef()const
{
	return this->coef;
}
void Branch::copy(const Branch& other)
{
	setId(other.id);
	setLocation(other.location);
	setCoef(other.coef);
}

Branch& Branch::operator++()
{	
	this->coef++;
	return *this;
}
ostream& operator<<(ostream& out, const Branch& other)
{
	out << "Id: " << other.id << endl
		<< "Location: " << other.location << endl
		<< "Coef: " << other.coef << endl;

	return out;
}
//************************************************//
class Bank
{
private:
	char name[30];
	Branch* branches;
	int wonClients;
	int lostClients;
	void copy(const Bank&);
	void destroy();
public:
		Bank();
		Bank(const Bank&);
		Bank& operator=(const Bank&);
		~Bank();

		Bank(const char*,Branch*);
		void setName(const char*);
		char* getName();
		friend ostream& operator<<(ostream&, const Bank&);
		friend double workCoef(const Bank&);
};
Bank::Bank()
{
	strcpy_s(this->name, 10, "Default");
	this->branches = new Branch[10];
	this->wonClients = 0;
	this->lostClients = 0;
}
Bank::Bank(const Bank& other)
{
	copy(other);
}
Bank::Bank(const char* newName,  Branch* newBranches)
{
	setName(newName);
	this->branches = newBranches;
}
Bank& Bank::operator=(const Bank& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}
void Bank::setName(const char* newName)
{
	strcpy_s(this->name, strlen(newName) + 1, newName);
}
char* Bank::getName()
{
	return this->name;
}
void Bank::copy(const Bank& other)
{
	this->branches = other.branches;
}
void Bank::destroy()
{
	delete[] this->branches;
}
Bank::~Bank()
{
	destroy();
}
ostream& operator<<(ostream& out, const Bank& other)
{
	out << "Name: " << other.name << endl;
	for (size_t i = 0; i < 10; i++)
	{
		out << other.branches[i] << endl;
	}
	return out;
}
double workCoef(const Bank& current)
{
	double sum = 0;
	for (size_t i = 0; i < 10; i++)
	{
		sum += current.branches[i].getCoef();
	}
	return sum / 10;
}

int main()
{
	Branch branches[10];
	branches[0] = Branch(2, "sofia", 22);
	branches[1] = Branch(1, "Sofia", 40);
	branches[2] = Branch(2, "Varna", 20);
	branches[3] = Branch(3, "Bugas", 20);
	branches[4] = Branch(4, "Russe", 15);
	branches[5] = Branch(5, "Yambol", 12);
	branches[6] = Branch(6, "V.Tarnovo", 15);
	branches[7] = Branch(7, "St.Zagora", 10);
	branches[8] = Branch(8, "Smolyan", 8);
	branches[9] = Branch(9, "Sliven", 3);


	Bank bank("DSK", branches);
	cout << branches[8] << endl;
	
    return 0;
}

