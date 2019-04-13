// preparation_test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Elf
{
private:
	char* name;
	int age;
	int ability;
public:
	//Elf();
	Elf(const char* = "default", const int& = 0, const int& = 0);
	Elf(const Elf&);
	~Elf();
	Elf& operator=(const Elf&);

	void setName(const char*);
	char* getName()const;

	void setAge(const int&);
	int getAge() const;

	void setAbility(const int&);
	int getAbility()const;

	void print() const;

	friend ostream& operator<<(ostream&,const Elf&);


};
/*
Elf::Elf()
{
	strcpy_s(this->name,7, "default");
	this->age = 0;
	this->ability = 0;
}
*/

Elf::Elf(const char* _name, const int& _age, const int& _ability) 
	: name(nullptr)
{
	setName(_name);
	setAge(_age);
	setAbility(_ability);
}

Elf::Elf(const Elf& other) : Elf(other.name,other.age,other.ability){}
Elf& Elf::operator=(const Elf& other)
{
	if (this != &other)
	{
		setName(other.name);
		setAge(other.age);
		setAbility(other.ability);
	}
	return *this;
}
Elf::~Elf()
{
	delete[] this->name;
}
void Elf::setName(const char* _name)
{
	if (_name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}
}
char* Elf::getName() const
{
	return this->name;
}

void Elf::setAge(const int& _age)
{
	this->age = _age;
}
int Elf::getAge() const
{
	return this->age;
}
void Elf::setAbility(const int& _ability)
{
	this->ability = _ability;
}
int Elf::getAbility()const
{
	return this->ability;
}
void Elf::print() const
{
	cout << this->name << endl;
	cout << this->age << endl;
	cout << this->ability << endl;
	
}
ostream& operator <<(ostream& out, const Elf& elf)
{
	out << elf.name << endl << elf.age << endl << elf.ability << endl;
	return out;
}
class ElfTeam
{
private:
	char name[30];
	Elf* elfs;
	size_t size;
	size_t capacity;

	void resize();

public:
	ElfTeam();
	//ElfTeam(const char _name[30] = "default", const Elf* _elfs = nullptr,
	 //	size_t size = 0, size_t capacity = 8);
	ElfTeam(const ElfTeam&);
	ElfTeam& operator= (ElfTeam&);
	~ElfTeam();
	
	void setName(const char*);
	char* getName();
	void add(const Elf&);
	void remove(const Elf&);
	
	//Elf& analyse(const DynamicArray&);
	friend double proportion(const ElfTeam& team, int size);
	//friend ElfTeam& operator+(const ElfTeam&);
	friend ostream& operator<<(ostream&, const ElfTeam& team);	
	friend bool operator<(const ElfTeam&,const ElfTeam&);

};


ElfTeam::ElfTeam()
{
	strcpy_s(this->name, 10, "default");
	this->elfs = new Elf[8];
	this->size = 0;
	this->capacity = 8;
}
ElfTeam::ElfTeam(const ElfTeam& otherTeam)
{
	this->size = otherTeam.size;
	this->capacity = otherTeam.capacity;
	strcpy_s(this->name, 30, otherTeam.name);

	this->elfs = new Elf[capacity];
	for (size_t i = 0; i < size; i++)
	{
		this->elfs[i] = otherTeam.elfs[i];
	}

}
ElfTeam& ElfTeam :: operator= ( ElfTeam& otherTeam)
{
	if (this != &otherTeam)
	{
		delete[] this->elfs;
		this->size = otherTeam.size;
		this->capacity = otherTeam.capacity;
		strcpy_s(this->name, 30, otherTeam.name);

		this->elfs = new Elf[capacity];
		for (size_t i = 0; i < size; i++)
		{
			this->elfs[i] = otherTeam.elfs[i];
		}

	}
	return *this;
}
ElfTeam::~ElfTeam()
{
	delete[] this->elfs;
}
void ElfTeam::resize()
{
	this->capacity *= 2;
	Elf* temp = new Elf[capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = this->elfs[i];
	}
	delete[] this->elfs;
	this->elfs = temp;
}
void ElfTeam::add(const Elf& newElf)
{
	if (size == capacity)
	{
		resize();
	}
	this->elfs[size] = newElf;
	size++;
}
void ElfTeam::remove(const Elf& currentElf)
{
	for (size_t i = 0; i < size; i++)
	{
		if (currentElf.getName() == elfs[i].getName()
			&& currentElf.getAge() == elfs[i].getAge()
			&& currentElf.getAbility() == elfs[i].getAbility())
		{
			elfs[i] = elfs[size];
			--size;
			return;
		}
	}
}
void ElfTeam::setName(const char* _name)
{
	strcpy_s(name, 30, _name);
}
char* ElfTeam::getName()
{
	return this->name;
}

double proportion(const ElfTeam& team, int size)
{
	int sumAges = 0, sumAbility = 0;
	for (size_t i = 0; i <team.size; i++)
	{
		sumAges += team.elfs[i].getAge();
		sumAbility += team.elfs[i].getAbility();
	}
	return sumAges / sumAbility;
}
bool operator<(const ElfTeam& teamA, const ElfTeam& teamB)
{
	return proportion(teamA, teamA.size) < proportion(teamB, teamB.size);
}

ostream& operator<<(ostream& out, const ElfTeam& team)
{
	out << team.name << endl;
	for (int i = 0; i < team.size; i++)
	{
		out << team.elfs[i] << endl;
	}
	return out;
}



int main()
{
	Elf e1("Daenerys", 0, 1);
	Elf e2("JonSnow", 20, 2);
	Elf e3("Rheagar", 5, 2);
	
	Elf e4("tomen", 10, 1);
	Elf e5("joffrey", 9, 1);
	Elf e6("mircela", 5, 2);

	//cout << e2 << endl;

	
	ElfTeam teamA;
	//cout << team << endl;
	teamA.setName("Targerian");
	teamA.add(e1);
	teamA.add(e2);
	teamA.add(e3);
	//cout << teamA << endl;

	ElfTeam teamB;
	teamB.setName("Lanister");
	teamB.add(e4);
	teamB.add(e5);
	teamB.add(e6);
	cout << teamA;
	cout << "__________________" << endl;
	//teamA = teamB;
	cout << teamA;
	bool res =  teamA < teamB;
	cout << "+++++++++++++++++" << endl;
	cout << proportion(teamA, 3) << endl;
	cout << proportion(teamB, 3) << endl;

	cout << boolalpha << res << endl;
	
	cout << teamA << endl;
	teamA.remove(e1);
	cout << "after changes" << endl;
	cout << teamA << endl;

    return 0;
}

