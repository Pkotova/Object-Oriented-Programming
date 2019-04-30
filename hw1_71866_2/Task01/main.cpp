// Task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Vector.cpp"
#include <iostream>
using namespace std;

int main()
{
	Vector<int> empty;
	Vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(55);
	v.push_back(2);
	v.push_back(5);
	v.push_back(6);
	v.push_back(0);
	v.push_back(4);
	//v.erase(3);		// works sometimes

	empty = v;
	empty.print();

	Vector<int> v2(v);	
	//v2.print();

	Vector<int> v3(4);
	cout <<"Capacity: "<< v3.capacity() << endl;
	cout <<"Size: " << v3.size() << endl;

	Vector<int> v4(2, 3);
	cout << "v4:" << endl;
	v4.print();

	cout <<"v[4] = "<< v[4] << endl;
	cout << "v[5] = " << v.at(5) << endl;
	cout << "front: " << v.front() << endl;
	cout << "back: " << v.back() << endl;
	cout << "is empty: " <<boolalpha<< v3.empty() << endl;
	v3.reserve(10);
	cout << "Capacity: " << v3.capacity() << endl;
	cout << "Size: " << v3.size() << endl;
	cout << endl;
	cout << "___________" << endl;
	cout << "Capacity: " << v.capacity() << endl;
	cout << "Size: " << v.size() << endl;
	v.shrink_to_fit();
	cout << "Capacity: " << v.capacity() << endl;
	cout << "Size: " << v.size() << endl;
	v.pop_back();
	v.print();

	cout << endl;
	Vector<int> vv = { 1,2};
	vv.print();
	
}

