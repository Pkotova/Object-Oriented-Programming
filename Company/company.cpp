#include <iostream>
#include <cstring>
using namespace std;

class Company
{
public:
    Company(const char* name = "Default name", int year = 1950,
            int employees = 0, double money = 0);
    Company(const Company& other);
    Company& operator=(const Company& other);
    ~Company();

    void setName(const char* name);
    void setYear(const int& year);
    void setEmployees(const int& empolyees);
    void setMoney(const double& money);

    const char* getName() const;
    int getYear() const;
    int getEmployees() const;
    double getMoney() const;

    void print() const;

private:
    char* name;
    int year;
    int employees;
    double money;

};

Company::Company(const char* name , int year, int employees, double money) : name(NULL)
{
    cout << "Default c-tor" << endl;
    setName(name);
    setYear(year);
    setEmployees(employees);
    setMoney(money);
}

Company::Company(const Company& other) : name(NULL)
{
    cout << "Copy c-tor" << endl;
    setName(other.name);
    setYear(other.year);
    setEmployees(other.employees);
    setMoney(other.money);

}

Company& Company::operator=(const Company& other)
{
    cout << "Operator =" << endl;
    if(this != &other){
        setName(other.name);
        setYear(other.year);
        setEmployees(other.employees);
        setMoney(other.money);
    }

    return *this;
}

Company::~Company()
{
    cout << "Destructor" << endl;
    delete [] name;
}

void Company::setName(const char* name)
{
	if (name != nullptr) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

void Company::setYear(const int& year)
{
    if(year >= 1950 && year <=2200) this->year = year;
}

void Company::setEmployees(const int& employees)
{
    if(employees > 0) this->employees = employees;
}

void Company::setMoney(const double& money)
{
    this->money = money;
}

const char* Company::getName() const
{
    return name;
}

int Company::getYear() const
{
    return year;
}

int Company::getEmployees() const
{
    return employees;
}

double Company::getMoney() const
{
    return money;
}

void Company::print() const
{
    cout << "Company's name: " << name << endl;
    cout << "Founded in: " << year << endl;
    cout << "Number of employees: " << employees << endl;
    cout << "Money: " << money << endl << endl;
}


int main()
{
    Company c1 = Company("c1", 1975, 25, 145698.25), c3;
    cout << "C1, C3 created" << endl;

    Company c4 = c1;
    cout << "C4 created" << endl;

    Company c2;
    cout << "C2 created" << endl;

    c2 = c1;
    cout << "C2 changed" << endl << endl;

    c1.setName("C1");
    c1.setMoney(200);

    c2.setName("c2");
    c2.setMoney(300);

    c3.setName("c3");
    c3.setMoney(400);

    c4.setName("c4");
    c4.setMoney(500);

    c1.print();
    c2.print();
    c3.print();
    c4.print();

    return 0;
}
