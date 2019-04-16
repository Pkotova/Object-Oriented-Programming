#pragma once
#include<iostream>
#include"Coefficient.h"
using namespace std;

class Polinom
{
private:
	Coefficient* coefficients;
	int size;
	int capacity;
	int power;

	void resize();
	void copy(const Polinom&);
	void destroy();

public:
	Polinom();
	Polinom(const Polinom&);
	Polinom& operator=(const Polinom&);
	~Polinom();

	//void setCoefficients(double*);
	//double* getCoefficients()const;
	
	void setSize(const int&);
	int getSize()const;

	void setCapacity(const int&);
	int getCapacity()const;

	int getPower()const;
	void setPower();

	void print();
	void add(const Coefficient&);
	Polinom(Coefficient*,const int&, const int&, const int);
	friend Polinom& operator^(Polinom&, Polinom&);
	friend Polinom& operator^=(Polinom&, Polinom&);

	friend Polinom operator*(const Polinom&, const Polinom&);
	friend bool operator >(const Polinom&, const Polinom&);
	friend bool operator <(const Polinom&, const Polinom&);
	friend bool operator >=(const Polinom&, const Polinom&);
	friend bool operator <=(const Polinom&, const Polinom&);
	friend bool operator ==(const Polinom&, const Polinom&);
	friend Polinom operator-( Polinom&,  Polinom&);
	friend Polinom operator&(const Polinom&, const double&);
	friend Polinom operator|(const Polinom&, const double&);
    Coefficient operator[](const int&);
	double operator()(const double&);
	friend Polinom operator~(const Polinom&);
	friend bool operator!(const Polinom&);
	friend Polinom operator+(Polinom&,Polinom&);
	friend Polinom operator/(Polinom&, Polinom&);
	friend Polinom operator%(Polinom&, Polinom&);
	friend ostream& operator<<(ostream&, const Polinom&);
	friend istream& operator>>(istream&, Polinom&);

};

