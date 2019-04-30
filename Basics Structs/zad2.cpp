#include <iostream>
#include <cmath>
using namespace std;

struct Rectangle
{
    double a; /// double a, b;
    double b;
};

void create(Rectangle& rect) /// cannot be const Rectangle& rect
{
    do{
        cout << "Enter rectangle's sides: ";
        cin >> rect.a >> rect.b;
    }while(rect.a <= 0 || rect.b <= 0);
}


/// the following functions do not change rect - they just access rect's fields
/// const does not allow changes in the function's body
void print(const Rectangle& rect)
{
    cout << "Rectangle: " << rect.a << " " << rect.b << endl;
}

double getRadius(const Rectangle& rect)
{
    return sqrt(rect.a * rect.a + rect.b * rect.b) / 2;
}

double getPerimeter(const Rectangle& rect)
{
    return (rect.a + rect.b) * 2;
}

double getArea(const Rectangle& rect)
{
    return rect.a * rect.b;
}

int main()
{
    Rectangle r;

    create(r); /// a = 15, b = 20
    print(r);

    cout << "Radius: " << getRadius(r) << endl;
    cout << "Perimeter: " << getPerimeter(r) << endl;
    cout << "Area: " << getArea(r) << endl;

    return 0;
}
