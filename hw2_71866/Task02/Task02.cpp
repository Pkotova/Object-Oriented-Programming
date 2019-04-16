// Task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "IceCreamFlavour.h"
#include "IceCream.h"
#include "IceCreamContainer.h"
#include <iostream>
using namespace std;

int main()
{
	IceCreamFlavour f("choco", 2);
	cout << f << endl;
	IceCream i;
	i.setName("kit");
	IceCream ii[2];
	IceCreamContainer c;
	cout << ii[0] << endl;
	ii[0].setName("koko");
	cout << ii[0];
	c.add(ii[0]);
	cout << c << endl;

	return 0;
}

