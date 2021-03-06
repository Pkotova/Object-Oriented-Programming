// Task01.cpp Calculate the common section of two reactangles in coordinate system
// Petya Kotova 71866 2group

#include "stdafx.h"
#include<iostream>
using namespace std;

struct Point
{
	double x,
		y;
};
struct Rectangle
{
	Point point;
	double width,
		   height;
};

void createReactangle(Rectangle& rectangle)
{
	cout << "Input coordinates of up right left of the reactangle: " << endl;
	cout << "x: ";
	cin >> rectangle.point.x;
	cout << "y: ";
	cin>> rectangle.point.y;

	cout << "Rectangle height: ";
	cin >> rectangle.height;

	cout << "Rectangle width: ";
	cin >> rectangle.width;
}

void getArea(Rectangle& rectangle1, Rectangle& rectangle2)
{
	//set coordinates of points of the section
	double xCoordRightPoint = 0.0;
	double xCoordLeftPoint = 0.0;
	double yCoordUpper = 0.0;
	double yCoordDown = 0.0;

	// calculating the measurement of the whole figure in the coordinate system
	double figureWidth = rectangle1.width + rectangle2.width;
	double figureHeight = rectangle1.height + rectangle2.height;

	// checking position of x coord
	 
	bool resultX = rectangle2.point.x + rectangle2.width > rectangle1.point.x + rectangle1.width;

	//calculating each rectangle width
	double widthRectangle1 = rectangle1.point.x + rectangle1.width;
	double widthRectangle2 = rectangle2.point.x + rectangle2.width;

	(!resultX) ? xCoordRightPoint = widthRectangle1 : xCoordRightPoint = widthRectangle2;

	bool checkPositionX = rectangle1.point.x < rectangle2.point.x;
	(!checkPositionX) ? xCoordLeftPoint = rectangle2.point.x 
					  : xCoordLeftPoint = rectangle1.point.x;

	//calculating section width
	double width = figureWidth - (xCoordRightPoint - xCoordLeftPoint);

	bool checkPositionY = rectangle1.point.y < rectangle2.point.y;
	(!checkPositionY) ? yCoordUpper = rectangle1.point.y 
		              : yCoordUpper = rectangle2.point.y;

	bool resultY = rectangle2.point.y - rectangle2.height > rectangle1.point.y - rectangle1.height;
	(!resultY) ? yCoordDown = rectangle2.point.y - rectangle2.height 
			   : yCoordDown = rectangle1.point.y - rectangle1.height;

	//calculating section height
	double height = figureHeight - (yCoordUpper - yCoordDown);

	//calculating area of the section
	double  innerArea = width * height;

	cout << "______RESULT_____" << endl;
	cout << "Inner Area: " << innerArea << endl;
}

int main()
{
	Rectangle rectangle1, rectangle2;
	createReactangle(rectangle1);
	createReactangle(rectangle2);
	getArea(rectangle1, rectangle2);
	/* 
		f.e. 
		rectangle { (coordinates of upper left point (x,y)), height, width }
		rectangle1 : (4,4), 3, 4
		rectangle2 : (7,4), 2, 2
		output: 1
	*/
	return 0;
}
