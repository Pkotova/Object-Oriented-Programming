#include <iostream>
using namespace std;

struct Complex
{
    private:
        double re, im;

    public:
        void create(double x, double y)
        {
            re = x; /// this->re = x;
            im = y; /// this->im = y;
        }

        void print() const
        {
            cout << re << (im < 0 ? "" : "+") << im << "i" << endl;
        }

        double getRe() const
        {
            return re;
        }

        double getIm() const
        {
            return im;
        }

        bool isZero() const
        {
            return (re == 0) && (im == 0);
        }

        Complex sum(const Complex& c) const
        {
            Complex p;
            p.create(re + c.re, im + c.im);
            return p;
        }

        Complex sub(const Complex& c) const
        {
            Complex p;
            p.create(re - c.re, im - c.im);
            return p;
        }

        Complex mult(const Complex& c) const
        {
            Complex p;
            p.create(re * c.re - im * c.im,
                     re * c.im + im * c.re);
            return p;
        }

        Complex quot(const Complex& c) const
        {
            Complex p;
            double den = c.re * c.re + c.im * c.im;

            p.create((re * c.re + im * c.im) / den,
                     (im * c.re - re * c.im) / den);
            return p;
        }
};

int main()
{
    Complex c1, c2;

    double a, b;
    cout << "re, im? ";
    cin >> a >> b;

    c1.create(a, b);

    cout << "re, im? ";
    cin >> a >> b;
    c2.create(a, b);

    cout << endl << "c1 + c2:" << endl;
    c1.sum(c2).print();

    cout << endl << "c1 - c2:" << endl;
    c1.sub(c2).print();

    cout << endl << "c1 * c2:" << endl;
    c1.mult(c2).print();

    cout << endl << "c1 / c2:" << endl;
    if(!c2.isZero()) c1.quot(c2).print();
    cout << "c2 is equal to zero!" << endl;


    return 0;
}
