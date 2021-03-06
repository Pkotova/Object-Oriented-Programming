// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Polinom.h"
#include "Coefficient.h";
#include<iostream>
using namespace std;

int main()
{
	Coefficient coefs[10];
	int n;
	cout << "How many coefs: " << endl;
	cin >> n;
	
	Polinom yourPolinom;
	yourPolinom.setSize(n);
	cin >> yourPolinom;
	yourPolinom.setPower();
	cout << "Created polinom: " << endl;
	cout << yourPolinom << endl;


	Coefficient coef[4];
	coef[0] = 2;
	coef[1] = 1;
	coef[2] = 4;
	coef[3] = 5;



	Polinom p;
	p.add(coef[0]);
	p.add(coef[1]);
	p.add(coef[2]);
	p.add(coef[3]);

	cout << "Operator = " << endl;
	Polinom p1 = p;		//operator =
	cout << "Polinom 1: " << endl;
	cout << p1 << endl;

	Polinom p2;
	p2.add(coef[2]);
	p2.add(coef[3]);

	Polinom p3;
	p3.add(coef[3]);
	p3.add(coef[2]);

	cout << endl;
	cout << "Polinom 2: " << endl;
	cout << p2 << endl;
	cout << endl;
	cout << "Polinom 3" << endl;
	cout << p3 << endl;

	cout << endl;
	cout << "Operator < (p2 < p2): " << endl;
	cout << boolalpha << (p1 < p2 )<< endl;

	cout << endl;
	cout << "Operator > (p2 > p2): " << endl;
	cout << boolalpha << (p1 > p2) << endl;

	cout << endl;
	cout << "Operator <= (p2 <=p2): " << endl;
	cout << boolalpha << (p1 <= p2) << endl;

	cout << endl;
	cout << "Operator >= (p2 < p2): " << endl;
	cout << boolalpha << (p1 >= p2) << endl;
	
	cout << endl;
	cout << "Operator * multyply polinoms" << endl;
	cout << p2 * p3 << endl;

	cout << endl;
	cout << "Operator p1 + p2 " << endl;
	cout << p1 + p2 << endl;

	cout << endl;
	cout << "Operator p1 - p2 " << endl;
	cout << p1 - p2 << endl;

	cout << endl;
	cout << "Operator polinom * (double = 4)" << endl;
	cout << (p1 & 4) << endl;

	cout << endl;
	cout << "Operator polinom / (double = 2)" << endl;
	cout << (p1 | 2) << endl;

	cout << endl;
	cout << "Operator p[index] " << endl;
	cout << p1[3] << endl;

	cout << endl;
	cout << "Operator p1(x) , x= 1" << endl;
	cout << p1(1) << endl;

	cout << endl;
	cout << "Operator f'(x) (polinom)" << endl;
	cout << ~p1 << endl;

	cout << endl;
	cout << "Get power of polinom " << endl;
	cout << p1.getPower() << endl;

	cout << endl;
	cout << "Operator !(if the polinom is empty)" << endl;
	cout << !p1 << endl;


	return 0;
}

