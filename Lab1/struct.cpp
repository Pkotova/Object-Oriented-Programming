#include <iostream>
using namespace std;

struct Child; /// forward declaration

struct Parent
{
    Child* child; /// Child child - invalid due to incomplete type
    int age;
};

struct Child
{
    Parent parent; /// Parent parent - valid
    int age;
};

int main()
{
    cout << "Hello, world!" << endl;

    return 0;
}
