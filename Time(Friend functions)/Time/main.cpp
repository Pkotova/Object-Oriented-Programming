#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time t1, t2(12, 15);

    t1.print();
    t2.print();

    Time t3 = t2;

    t3.print();
    t3.setMinutes(105);

    t3.print();

    cout << "t3 in minutes: " << t3 << endl; /// !!!

    Time t4 = t2 + t3;
    cout << "t2 + t3: ";
    t4.print();

    cout << "t3 - t2: ";
    t1 = t3 - t2;
    t1.print();


    return 0;
}
