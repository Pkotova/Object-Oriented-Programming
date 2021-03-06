// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Fraction
{
private: 
	int x, y;
public:
	Fraction();
	Fraction(int,int);
	int getX() const;
	int getY() const;
	void setX(int);
	void setY(int);
	void print()const;
	bool friend isFraction(const Fraction&);
	operator double();
};
Fraction::Fraction()
{
	x = 0;
	y = 1;
}
Fraction::Fraction(int newX, int newY)
{
	this->x = newX;
	this->y = (newY != 0) ? newY : 1;
}
void Fraction::setX(int newX) 
{
	this->x = newX;
}
void Fraction::setY(int newY) 
{
	this->y = newY;
}
int Fraction::getX()const
{
	return this->x;
}
int Fraction::getY()const
{
	return this->y;
}
void Fraction::print()const
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}
Fraction::operator double()
{
	return (double)x / y;
}
bool isFraction(const Fraction& obj)
{
	return obj.x % obj.y != 0;
}
int main()
{
	Fraction f;
	f.setX(2);
	f.setY(5);
	cout << boolalpha << isFraction(f) << endl;
	f.print();
	cout << f << endl;
    return 0;
}


