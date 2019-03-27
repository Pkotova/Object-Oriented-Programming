#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x, y;
};

void readPoint(Point& point)
{
    bool valid;
    do{
        cout << "Enter coordinates in range [1, 100]: ";
        cin >> point.x >> point.y;

        valid = (point.x >= 1 && point.x <= 100)
                && (point.y >= 1 && point.y <= 100);
    }while(!valid);
}

void printPoint(const Point& point)
{
    cout << "Point: " << point.x << " " << point.y << endl;
}

double getDistance(const Point& p1, const Point& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool onLine(const Point& p1, const Point& p2)
{
    return p1.x == p2.x || p1.y == p2.y;
}

int main()
{
    Point a, b, c, d;

    readPoint(a);
    readPoint(b);
    readPoint(c);
    readPoint(d);

    bool rectangle = onLine(a, b) && onLine(b, c) && !onLine(a, c)
                && onLine(c, d) && onLine(d, a) && !onLine(b, d);

    if(rectangle){
        double top = getDistance(a, b);
        double left = getDistance(b, c);
        double bottom = getDistance(c, d);
        double right = getDistance(d, a);

        if(top == bottom && left == right && top == left){
            cout << "Square" << endl;
        }else{
            cout << "Rectangle" << endl;
        }
    }else{
        cout << "other" << endl;
    }

    return 0;
}
