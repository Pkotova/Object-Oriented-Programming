#pragma once
#include<iostream>
using namespace std;
class Fish
{
private:
	char* type;
	double weight;
	double price;

	void copy(const Fish&);
	void destroy();

public:
	Fish();
	Fish(const Fish&);
	Fish& operator=(const Fish&);
	Fish(const char*, const double&, const double&);
	~Fish();

	void setType(const char*);
	char* getType()const;
	void setWeight(const double&);
	double getWeight()const;
	void setPrice(const double&);
	double getPrice();

	friend bool operator<(const Fish&, const Fish&);
	friend bool operator>(const Fish&, const Fish&);
	friend bool operator<=(const Fish&, const Fish&);
	friend bool operator>=(const Fish&, const Fish&);
	friend bool operator==(const Fish&, const Fish&);
	friend bool operator!=(const Fish&, const Fish&);

	friend ostream& operator<<(ostream&, const Fish&);
	friend istream& operator>>(istream&, Fish&);
};

