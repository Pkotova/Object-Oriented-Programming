#pragma once
class Triangle
{
protected:
	double a;
	double b;
	double c;
public:
	Triangle();
	Triangle(double, double, double);

	void setA(double&);
	double getA()const;

	void setB(double&);
	double getB()const;

	void setC(double&);
	double getC()const;

	double area();
	double perimeter();
	void print();

	//~Triangle();
};

