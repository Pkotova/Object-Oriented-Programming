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
	
	IceCreamFlavour
		f1("Vanilla and fruits", 1.2),
		f2("Chocolate", 1.8),
		f3("Cherry", 1.6),
		f4("Banana", 1.4);

//you can use operators >> << for all classes 

//		IceCreamFlavour flavour;
//		cin >> flavour;
//		cout << flavour;

	IceCream
		i1("Vanilla Dream", f1, 2),
		i2("Choco", f2, 1),
		i3("Cherry pie", f3, 2),
		i4("Monkey", f4, 2);

//		IceCream iCream;
//		cin >> iCream;
//		cout << iCream;

// comparison operators
		cout << "(i1 < i4)  : ";
		cout << boolalpha << (i1 < i4) << endl;

		cout << "(i2 > i1)  : ";
		cout << boolalpha << (i2 > i1) << endl;

		cout << "(i3 <= i4) : ";
		cout << boolalpha << (i3 <= i4) << endl;

		cout << "(i2 >= i4) : ";
		cout << boolalpha << (i2 >= i4) << endl;

		cout << "(i3 == i3) : ";
		cout << boolalpha << (i3 == i3) << endl;

		cout << "(i3 == i1) : ";
		cout << boolalpha << (i3 == i1) << endl;

		cout << "(i3 != i2) : ";
		cout << boolalpha << (i3 != i2 )<< endl;


//class container
	IceCream dflt;
		cout << endl;
		cout << "Your default container:" << endl;
		cout << dflt << endl;

	IceCreamContainer container;
		container.add(i1);							//add method
		container.add(i2);
		container.add(i3);
		container.add(i4);
		container.add(i4);

//		IceCreamContainer container;
//		cin >> container;
//		cout << container;

		cout << endl;
		cout << "Capacity before removing: ";
		cout << container.getCapacity() << endl;
		container.remove(4);					  //remove method
		cout << "Capacity after removing: ";
		cout << container.getCapacity() << endl;  //changing capacity

		cout << container << endl;
		cout << "- Checking if there is current ice cream: "; 
		cout << boolalpha << container.has(i2) << endl;
		cout << "- Report: ";
		cout << container.report()<<"BGN"<< endl;

	return 0;
}

