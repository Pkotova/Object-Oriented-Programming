#include <iostream>
using namespace std;

class Employee
{
    private:
        char name[32];
        int year;
        double salary;

    public:
        void create();
        void print() const;
};



void Employee::create()
{
    cout << "Enter name: ";
    cin.getline(name, 32);

    cout << "Enter year of birth: ";
    cin >> year;

    cout << "Enter salary: ";
    cin >> salary;
    cin.ignore();
}

void Employee::print() const
{
    cout << "Name: " << name << endl;
    cout << "Year of birth: " << year << endl;
    cout << "Salary: " << salary << endl;
}


int main()
{
    Employee e1, e2;

    e1.create();
    e1.print();

    e2.create();
    e2.print();

    return 0;
}
