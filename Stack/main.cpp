#include "pch.h"
#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack s1(5);

	cout << boolalpha << s1.isEmpty() << endl;
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s1.push('d');
	s1.push('e');
	s1.push('f');
	cout << "Size: " << s1.getSize() << endl;
	cout << "Top element: " << s1.top() << endl;

	Stack s2 = s1;
	cout << boolalpha << s2.isEmpty() << endl;

	return 0;
}