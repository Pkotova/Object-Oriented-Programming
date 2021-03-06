// Fish.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Fish.h"
#include"Fisherman.h"
#include<iostream>
using namespace std;


int main()
{
// class Fish
	Fish
		f1("Caca", 0.100, 2.0),
		f2("Sharan", 2.5, 7),
		f3("Skumria", 0.5, 3),
		f4("Lavrak", 0.4, 4);
	cout << "(f1 < f2)  : "<<boolalpha << (f1 < f2 )<< endl;
	cout << "(f1 > f2)  : " << boolalpha << (f3 > f2) << endl;
	cout << "(f1 <= f2) : " << boolalpha << (f1 <= f3) << endl;
	cout << "(f1 >= f2) : " << boolalpha << (f4 >= f1) << endl;
	cout << "(f1 == f2) : " << boolalpha << (f2 == f2) << endl;
	cout << "(f1 != f1) : " << boolalpha << (f1 != f1) << endl;

	Fisherman fm1;
	fm1.setName("Ico");
	fm1.addFish(f1);
	fm1.addFish(f2);
	cout << "Fisherman 1: " << endl;
	cout << fm1 << endl;
	cout << "Fisherman 1 has caught: " << fm1.getSize() << endl;

	cout << endl;

	Fisherman fm2;
	fm2.setName("Rado");
	fm2.addFish(f3);
	fm2.addFish(f4);
	cout << "Fisherman 2: " << endl;
	cout << fm2 << endl;
	cout << "Fisherman 2 has caught: " << fm2.getSize() << endl;

	cout<<"Biggest fish - fisherman 1: "<<fm1.biggestFish() << endl;
	cout <<"Biggest fish - fisherman 2: " << fm2.biggestFish() << endl;

	cout << "RACE:" << endl;
	cout << compareTo(fm1, fm2).getName()<< endl;
    return 0;
}

