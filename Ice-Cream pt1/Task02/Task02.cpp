// Task02.cpp : Ice creams - create array, print current ice cream by given money, print all same ice creams
//

#include "stdafx.h"
#include<iostream>
#include"IceCream.h";
#include"IceCreamFlavour.h";

using namespace std;

const int MAX = 10;

IceCream findSuitableIceCream(IceCream* iceCreams, double pinMoney, int size)
{
	int maxBalls = iceCreams[0].getBalls();
	double maxPrice = iceCreams[0].getPrice();
	IceCream current;
	
	for (int i = 0; i < size; i++)
	{
		if (iceCreams[i].getPrice() <= pinMoney)
		{
			if (iceCreams[i].getBalls() >= maxBalls)
			{
				current = iceCreams[i];
			}
			else if (iceCreams[i].getBalls() == maxBalls)
			{
				if (iceCreams[i].getPrice() >= current.getPrice())
				{
					current = iceCreams[i];
				}
			}
			else cout << "No such ice cream" << endl;
		}
	}

	return current ;
}

void printCurrentIceCreams(IceCreamFlavour flavour,IceCream* iceCreams, int size)
{
	cout << endl << "All ice creams with " << flavour.flavourName << endl;
	cout << "______________________________" << endl;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(iceCreams[i].getFlavour().flavourName, flavour.flavourName) == 0)
		{
			iceCreams[i].print();
		}
		else cout << "No such ice cream" << endl;
	}
}

int main()
{
	/*IceCream iceCreams[MAX];
	double pinMoney;
	int size;
	cout << "How many ice creams you want to create: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		iceCreams[i].create();
	}

	cout << "Amount of pin money: ";
	cin >> pinMoney;
	IceCream iceCreamForChild = findSuitableIceCream(iceCreams, size, pinMoney);
	cout << endl << "The most suitable ice cream for the child " << iceCreamForChild.getName() << endl;
	*/
	IceCreamFlavour flavour("chocolate", 1.0);
	IceCream i(flavour, 12, "hello");
	i.print();

	return 0;
}

