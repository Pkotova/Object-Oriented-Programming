#include "pch.h"
#include<cmath>
#include<iostream>
#include "Triangle.h"


Triangle::Triangle()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
}
Triangle::Triangle(double _a, double _b, double _c)
{
	this->a = _a;
	this->b = _b;
	this->c = _c;
}
void Triangle::setA(double& _a)
{
	this->a = _a;
}
void Triangle::setB(double& _b)
{
	this->b = _b;
}

void Triangle::setC(double& _c)
{
	this->c = _c;
}
double Triangle::getA()const
{
	return this->a;
}
double Triangle::getB()const
{
	return this->b;
}

double Triangle::getC()const
{
	return this->c;
}

double Triangle::area() 
{
	double p = (this->perimeter())/ 2.0;
	return sqrt(p* (p - a)* (p - b)* (p - c));
}
double Triangle::perimeter()
{
	return (this->a + this->b + this->c);
}
void Triangle::print()
{
	std::cout <<"a = "<< this->a << std::endl;
	std::cout <<"b = "<< this->b << std::endl;
	std::cout <<"c = "<< this->c << std::endl;

}

