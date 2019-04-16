#include "stdafx.h"
#include "Polinom.h"
#include "Coefficient.h"
#include<iostream>

using namespace std;
void Polinom::copy(const Polinom& other)
{
	this->power = other.power;
	this->size = other.size;
	this->capacity = other.capacity;
	this->coefficients = new Coefficient[capacity];
	for (int i = 0; i < other.size; i++)
	{
		this->coefficients[i] = other.coefficients[i];
	}
}
void Polinom::destroy()
{
	delete[] this->coefficients;
}
Polinom::Polinom()
{
	this->capacity = 4;
	this->coefficients = new Coefficient[this->capacity];
	this->size = 0;
	this->power = 0;
}
Polinom::Polinom(const Polinom& other)
{
	copy(other);
}
Polinom::Polinom(Coefficient* newCoefs,const int& newPower, const int& newSize, const int newCapacity)
{
	this->coefficients = newCoefs;
	this->power = newPower;
	this->size = newSize;
	this->capacity = newCapacity;
}

Polinom& Polinom::operator=(const Polinom& other) 
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}
Polinom::~Polinom()
{
	destroy();
}
//_________________________________
void Polinom::resize()
{
	this->capacity *= 2;
	this->capacity *= 2;
	Coefficient* temp = new Coefficient[capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->coefficients[i];
	}
	destroy();
	this->coefficients = temp;
}

//void Polinom::setCoefficients(double* newCoefs)
//{
//	//this->coefficients = newCoefs;
//	for (size_t i = 0; i < 4; i++)
//	{
//		this->coefficients[i] = newCoefs[i];
//	}
//}
//double* Polinom::getCoefficients()const
//{
//	return this->coefficients;
//}
void Polinom::setSize(const int& newSize)
{
	this->size = newSize;
}
int Polinom::getSize()const
{
	return this->size;
}
void Polinom::setCapacity(const int& newCapacity)
{
	this->capacity = newCapacity;
}
int Polinom::getCapacity()const
{
	return this->capacity;
}
int Polinom::getPower() const
{
	return this->power;
}
void Polinom::setPower()
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->coefficients[i].getCoef() != 0)
		{
			this->power = this->size - 1;
		}
	}
}
void Polinom::print()
{

	cout << "Coefficients:" << endl;
	for (int i = this->size - 1; i >= 0; i--)
	{
		cout << showpos << " " << this->coefficients[i] << "x^" << noshowpos << i;
	}
	cout << " = 0";
	cout << endl;
}
void Polinom::add(const Coefficient& coef)
{
	if (size == capacity)
	{
		resize();
	}
	this->coefficients[size] = coef;
	size++;
	if (coef.getCoef() != 0)
	{
		this->power = this->size - 1;
	}

}
ostream& operator<<(ostream& out, const Polinom& other)
{
	for (int i = other.size - 1; i >= 0; i--)
	{
		out << showpos << " " << other.coefficients[i] << "x^" << noshowpos << i;
	}
	cout << " = 0";

	return out;
}

istream& operator >>(istream &in, Polinom &p)
{
	cout << "Imput coefs: " << endl;
	for (int i = 0; i < p.getSize(); i++)
	{
		in >> p.coefficients[i];
	}
	return in;
}

Polinom& operator^(Polinom& p1, Polinom& p2)
{
	return (p1.getPower() > p2.getPower()) ? p1 : p2;
}
Polinom& operator^=(Polinom& p1, Polinom& p2)
{
	return (p1.getPower() < p2.getPower()) ? p1 : p2;
}
bool operator<(const Polinom& p1, const Polinom& p2)
{
	return (p1.getPower() < p2.getPower()) ? true : false;
}
bool operator>(const Polinom& p1, const Polinom& p2)
{
	return (p1.getPower() > p2.getPower()) ? true : false;
}
bool operator==(const Polinom& p1, const Polinom& p2)
{
	bool result = true;
	if (p1.getPower() == p2.getPower())
	{
		for (int i = 0; i < p1.getPower(); i++)
		{
			if (p1.coefficients[i].getCoef() != p2.coefficients[i].getCoef())
			{
				return !result;
			}
		}
	}
	else return !result;
}
bool operator>=(const Polinom& p1, const Polinom& p2)
{
	return (p1.getPower() >= p2.getPower()) ? true : false;
}
bool operator<=(const Polinom& p1, const Polinom& p2)
{
	return (p1.getPower() <= p2.getPower()) ? true : false;
}
Polinom operator&(const Polinom& p, const double& k)
{
	Polinom temp;
	for (int i = 0; i < p.getSize(); i++)
	{
		temp.add((k * (p.coefficients[i].getCoef())));
	}
	return temp;
}
Polinom operator|(const Polinom& p, const double& k)
{
	Polinom temp;
	for (int i = 0; i < p.getSize(); i++)
	{
		temp.add(((p.coefficients[i].getCoef()) / k));
	}
	return temp;
}
Coefficient Polinom::operator[](const int& index)
{
	Coefficient c;
	c.setCoefficient(0);
	if (index <= size)
	{
		return this->coefficients[index];
	}
	return c;
}
double Polinom::operator()(const double& x)
{
	int result = 0;
	for (int i = 0; i < this->getSize(); i++)
	{
		result += (x * this->coefficients[i].getCoef());
	}
	return result;
}

int minimum(int s1, int s2)
{
	return (s1 < s2) ? s1 : s2;
}
int maximum(int s1, int s2)
{
	return (s1 > s2) ? s1 : s2;
}
Polinom operator+(Polinom& p1, Polinom& p2)
{
	Polinom temp;
	for (int i = 0; i < minimum(p1.size, p2.size); i++)
	{
		temp.add(p1.coefficients[i].getCoef() + p2.coefficients[i].getCoef());
	}
	for (int i = minimum(p1.size, p2.size); i < maximum(p1.size, p2.size); i++)
	{
		temp.add(( p1 ^ p2).coefficients[i]);
	}

	return temp;
}
Polinom operator-(Polinom& p1, Polinom& p2)
{

	Polinom temp;
	for (int i = 0; i < minimum(p1.size, p2.size); i++)
	{
		temp.add(p1.coefficients[i].getCoef() - p2.coefficients[i].getCoef());
	}
	if (p2 > p1)
	{
		for (int i = p1.getSize(); i < p2.getSize(); i++)
		{
			temp.add(-(p2.coefficients[i].getCoef()));
		}
	}
	else 
	{
		for (int i = p1.getSize(); i < p2.getSize(); i++)
		{
			temp.add((p1.coefficients[i].getCoef()));
		}
	}
	return temp;
}
Polinom operator~(const Polinom& p)
{
	Polinom temp;
	for (int i = 1; i < p.getSize(); i++)
	{
		temp.add(((p.getSize() - 1) *  p.coefficients[i].getCoef()));
	}
	return temp;
}
Polinom  operator*(const Polinom& p1, const Polinom& p2)
{
	int powers = (p1.getSize() + p2.getSize()) - 1;
	Polinom temp;
	temp.setSize(powers);
	for (size_t i = 0; i < powers; i++)
	{
		temp.add(0);
	}
	for (int i = 0; i < p1.getSize(); i++)
	{
		for (int j = 0; j < p2.getSize(); j++)
		{
			temp.coefficients[i+j] = temp.coefficients[i+j].getCoef() + p1.coefficients[i].getCoef() 
				* p2.coefficients[j].getCoef();
		}
	}
	return temp;
}
 bool operator!(const Polinom& p)
{
	 for (int i = 0; i < p.getSize(); i++)
	 {
		 if (p.coefficients[i].getCoef() != 0)
		 {
			 return false;
		 }
	 }
	 return false;
}
