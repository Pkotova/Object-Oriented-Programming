#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

class Person
{
public:
	Person();
	Person(const char*, int, double, double);
	Person(const Person& other); //copy constructor
	Person& operator=(const Person& other);
	~Person();

	void setName(const char*);
	const char* getName() const;

	void setAge(int);
	int getAge() const;

	void setHeight(double);
	double getHeight() const;

	void setWeight(double);
	double getWeight() const;

	void print() const;
	double getBMI() const;

private:
	char* name;
	int age;
	double height;
	double weight;
};
Person::~Person()
{
	delete [] name;
}
Person::Person() : Person("Mimi", 20, 1.6, 66)
{

}
Person::Person(const Person& other) : name(NULL) 
//: Person(other.name,other.age,other.height,other.weight)
{
	setName(other.name);
	setAge(other.age);
	setHeight(other.height);
	setWeight(other.weight);
}
Person & Person::operator=(const Person & other)
{
	if (this != &other)
	{
		setName(other.name);
		setAge(other.age);
		setHeight(other.height);
		setWeight(other.weight);
	}
	return *this;
}
Person::Person(const char* newName, int newAge, double newHeight, double newWeight)
	:name(NULL)
{
	setName(newName);
	setAge(newAge);
	setHeight(newHeight);
	setWeight(newWeight);
}

void Person::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name,strlen(name) + 1, name);
}
void Person::setAge(int age)
{
	this->age = age;
}
void Person::setHeight(double height)
{
	this->height = height;
}
void Person::setWeight(double weight)
{
	this->weight = weight;
}
const char* Person::getName() const
{
	return name;
}
int Person::getAge() const
{
	return age;
}
double Person::getHeight()const
{
	return height;
}
double Person::getWeight() const
{
	return weight;
}
void Person::print() const
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Height: " << height << endl;
	cout << "Weight: " << weight << endl;
}
double Person::getBMI() const
{
	return weight / (height * height);
}
int main()
{
	
	/*
	Person p1("Lili", 20, 150, 66);
	Person p2, p3 = p1;
	p1.setName("Kiki");
	p1.print();
	p2.print();
	p3.print();
	*/
	Person* people = new Person[3];
	for (int i = 0; i < 3; i++)
	{
		people[i].print();
	}

    return 0;
}

