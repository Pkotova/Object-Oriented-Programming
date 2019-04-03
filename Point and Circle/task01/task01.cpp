// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Point
{
private:
	int x, y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	~Point(){}
	Point& operator +=(const Point & other)
	{

	}
	friend ostream& operator<<(ostream& out, const Point & obj)
	{
		out << "X: " << obj.x << "  Y: " << obj.y << endl;
		return out;
	}

};
class Circle
{
private:
	Point center;
	size_t radius;
public:
	Circle()
	{
		radius = 0;
	}
	Circle(Point p, size_t r)
	{
		this->center = p;
		this->radius = r;
	}

	~Circle();


};


class String
{
private:
	char * strng;
	size_t sz;
public:
	String()
	{
		cout << "C-tor" << endl;
		this->strng = nullptr;
		sz = 0;
	}
	~String()
	{
		cout << "Dstr-tor" << endl;
		delete[] strng;
	}

};

int main()
{
	String s;
	Point p(12, 16);
	cout << p << endl;
    return 0;
}

