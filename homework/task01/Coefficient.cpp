#include "stdafx.h"
#include "Coefficient.h"

Coefficient::Coefficient()
{
	this->coefficient = 0;
}
Coefficient::Coefficient(const double& newCoef)
{
	this->coefficient = newCoef;
}
void Coefficient::setCoefficient(const double newCoef)
{
	this->coefficient = newCoef;
}
double Coefficient::getCoef() const
{
	return this->coefficient;
}
ostream& operator<<(ostream& out, const Coefficient& coef)
{
	out << coef.coefficient;
	return out;
}
istream& operator>>(istream& in, Coefficient& c)
{
	in >>c.coefficient;
	return in;
}

Coefficient& Coefficient::operator=(const Coefficient& other)
{
	if (this != &other)
	{
		setCoefficient(other.coefficient);
	}
	return *this;
}
Coefficient operator+(Coefficient& c1,Coefficient& c2)
{
	Coefficient temp = c1.getCoef() + c2.getCoef();
	return temp;
}

