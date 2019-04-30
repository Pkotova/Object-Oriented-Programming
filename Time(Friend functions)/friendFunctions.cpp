#include <iostream>
#include <iomanip>
using namespace std;

class Fraction
{
    public:
        Fraction(int x, int y);
        int getX() const;
        int getY() const;

        friend bool isFraction(const Fraction& obj);

    private:
        int x;
        int y;
};

Fraction::Fraction(int x, int y)
{
    this->x = x;
    this->y = (y != 0) ? y : 1;
}

int Fraction::getX() const
{
    return x;
}

int Fraction::getY() const
{
    return y;
}

bool isFraction(const Fraction& obj)
{
    return obj.x % obj.y != 0;
}


int main()
{
    Fraction f1(2, 4), f2(2, 0); /// !!!

    cout << "isFraction(f1): " << boolalpha << isFraction(f1) << endl;
    cout << "isFraction(f2): " << boolalpha << isFraction(f2) << endl;

    return 0;
}
