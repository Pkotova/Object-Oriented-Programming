#include <iostream>
#include "String.h"
#include <cstring>
using namespace std;

int main()
{
    String s1("this "), s2("is a test"), s3("abcdef");

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl << endl;

    cout << s1 << s2 << endl;

    /// String cat = s1 + s2; cout << cat < <endl;
    cout << s1 + s2 << endl << endl;;

    cout << "Is s1 ascending? " << boolalpha
         << s1.isAscending() << endl;

    cout << "Biggest in s3: " << s3.findBiggest() << endl;

    cout << "Is s3 ascending? " << boolalpha
         << s3.isAscending() << endl;

    cout << "Length of s3: " << strlen("abcdef") << endl;
    cout << "After drop: " << s3.drop(3) << endl;

    return 0;
}
