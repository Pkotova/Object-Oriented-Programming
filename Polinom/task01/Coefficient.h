#pragma once
#include<iostream>
using namespace std;
class Coefficient
{
private:
	double coefficient;
public:
	Coefficient();
	Coefficient(const double& newCoef);
	Coefficient& operator = (const Coefficient&);
	void setCoefficient(const double newCoef);
	double getCoef() const;
	friend ostream& operator<<(ostream&, const Coefficient&);
	friend istream& operator>>(istream&, Coefficient&);

	friend Coefficient operator+(Coefficient&, Coefficient&);
	//~Coefficient();
};

