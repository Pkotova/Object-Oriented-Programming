// inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class base
{
	private: int b1;
	public: int b2;
	protected: int b3();
};

class der : public base
{
	private: int d1;
	public: int d2;
	public: int d3();
};

int base::b3()
{
	return 5;
}

/// should work
int der::d3()
{
	cout << b2 << endl;
	cout << d1 << " " << d2 << endl;
	return b2 + d2;
}


int main()
{
	/// should work
	der d1, d2;
	d1.d2 = 15;
	d1.b2 = 25;
	d1.d3();


	/// each line should cause an error
	//d2.b1 = 8;
	//d2.d1 = 22;
	//d2.b3();

	return 0;
}
