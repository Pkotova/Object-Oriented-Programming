// Trian-Rectan-IsoscelesTrian.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"Triangle.h"
#include <iomanip>   
#include <iostream>
using namespace std;

int main()
{
	Triangle t(1,2,2);
	cout << "Area:"<< t.area() << endl;
	cout << "Perimeter: " << t.perimeter() << endl;
	t.print();
}

