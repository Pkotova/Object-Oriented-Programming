// ElfTeam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
// Rewriting_Elfs.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<cstring>
using namespace std;

class Elf
{
private:
	char* name;
	int age;
	int ability;

	void destroy();
	void copy(const Elf&);
public:
	Elf();
	Elf(const Elf&);
	Elf& operator=(const Elf&);
	~Elf();

	Elf(const char*, const int&, const int&);

	void setName(const char*);
	char* getName() const;

	void setAge(const int&);
	int getAge()const;

	void setAbility(const int&);
	int getAbility()const;

	void print()const;
	friend ostream& operator<<(ostream&, const Elf&);
	friend bool operator==(const Elf&, const Elf&);

};
Elf::Elf() : name(nullptr)
{
	setName("Default");
	setAge(0);
	setAbility(0);
}
Elf::Elf(const Elf& other)
{
	copy(other);
}
Elf& Elf::operator=(const Elf& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
Elf::~Elf()
{
	destroy();
}
Elf::Elf(const char* _name, const int& _age, const int& _ability) : name(nullptr)
{
	setName(_name);
	setAge(_age);
	setAbility(_ability);
}
void Elf::copy(const Elf& other)
{
	setName(other.name);
	setAge(other.age);
	setAbility(other.ability);
}
void Elf::destroy()
{
	delete[] this->name;
}
void Elf::setName(const char* newName)
{
	if (newName != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}
char* Elf::getName() const
{
	return this->name;
}
void Elf::setAge(const int& newAge)
{
	this->age = newAge;
}
int Elf::getAge()const
{
	return this->age;
}
void Elf::setAbility(const int& newAbility)
{
	this->ability = newAbility;
}
int Elf::getAbility()const
{
	return this->ability;
}
void Elf::print()const
{
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Ability: " << this->ability << endl;
}
ostream& operator <<(ostream& out, const Elf& elf)
{
	out << "Name: " << elf.name << endl
		<< "Age: " << elf.age << endl
		<< "Ability: " << elf.ability << endl;
	return out;
}
bool operator==(const Elf& e1, const Elf& e2)
{
	return ((strcmp(e1.name, e2.name) == 0) &&
		(e1.age == e2.age) &&
		(e1.ability == e2.ability));
}

//***************************************************//

class ElfTeam
{
private:
	char teamName[30];
	Elf* team;

	size_t capacity;
	size_t size;
	void resize();

	void copy(const ElfTeam&);
	void destroy();
public:
	ElfTeam();
	ElfTeam(const ElfTeam&);
	ElfTeam& operator=(const ElfTeam&);
	~ElfTeam();
	ElfTeam(const char*, Elf*, const size_t&, const size_t&);
	//void setSize(const int&);B
	//int getSize()const;
	//void setCapacity(const int&);
	//int getCapacity()const;
	// май не ни трябват за тази задача
	void setName(const char*);
	char* getTeamName();
	void add(const Elf&);

	friend double proportion(const ElfTeam&);
	friend bool operator<(const ElfTeam&, const ElfTeam&);
	friend ostream& operator<<(ostream&, const ElfTeam&);
	friend ElfTeam operator+(const ElfTeam&, const ElfTeam&);
	friend ElfTeam& operator+=(const ElfTeam&, const ElfTeam&);
	friend int sumAbilities(const ElfTeam&);
	friend void sort(ElfTeam&);
	friend void sortTeamsP(ElfTeam**, int);
	friend void sortTeams(ElfTeam*, int);

};
ElfTeam::ElfTeam()
{
	strcpy_s(this->teamName, 10, "default");
	this->team = new Elf[8];
	this->size = 0;
	this->capacity = 8;
}
ElfTeam::ElfTeam(const char* newName, Elf* newTeam, const size_t& newSize, const size_t& newCapacity)
{
	strcpy_s(this->teamName, strlen(newName) + 1, newName);
	this->team = newTeam;
	this->size = newSize;
	this->capacity = newCapacity;
}
ElfTeam::ElfTeam(const ElfTeam& other)
{
	copy(other);
}
ElfTeam& ElfTeam::operator=(const ElfTeam& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
ElfTeam::~ElfTeam()
{
	destroy();
}
void ElfTeam::copy(const ElfTeam& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	strcpy_s(this->teamName, 30, other.teamName);

	this->team = new Elf[capacity];
	for (size_t i = 0; i < size; i++)
	{
		this->team[i] = other.team[i];
	}
}
void ElfTeam::resize()
{
	this->capacity *= 2;
	Elf* temp = new Elf[capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = this->team[i];
	}
	destroy();
	this->team = temp;
}
void ElfTeam::setName(const char* newName)
{
	strcpy_s(this->teamName, strlen(newName) + 1, newName);
}
char* ElfTeam::getTeamName()
{
	return this->teamName;
}

void ElfTeam::destroy()
{
	delete[] this->team;
}
void ElfTeam::add(const Elf& newElf)
{
	if (size == capacity)
	{
		resize();
	}
	this->team[size] = newElf;
	size++;
}
double proportion(const ElfTeam& team)
{
	int sumAges = 0, sumAbility = 0;
	for (size_t i = 0; i < team.size; i++)
	{
		sumAges += team.team[i].getAge();
		sumAbility += team.team[i].getAbility();
	}
	return sumAges / sumAbility;
}
bool operator<(const ElfTeam& teamA, const ElfTeam& teamB)
{
	return proportion(teamA) < proportion(teamB);
}
ElfTeam operator+(const ElfTeam& teamA, const ElfTeam& teamB)
{
	ElfTeam temp;

	for (size_t i = 0; i < teamA.size; i++)
	{
		temp.add(teamA.team[i]);
	}
	for (size_t i = 0; i < teamB.size; i++)
	{
		temp.add(teamB.team[i]);
	}
	return temp;
}
ElfTeam& operator+=(ElfTeam& teamA, ElfTeam& teamB)
{
	ElfTeam temp = teamA + teamB;
	teamA = temp;
	return teamA;
}
ostream& operator<<(ostream& out, const ElfTeam& team)
{
	out << team.teamName << endl;
	for (int i = 0; i < team.size; i++)
	{
		out << team.team[i] << endl;
	}
	return out;
}
int sumAbilities(const ElfTeam& team)
{
	int sum = 0;
	for (size_t i = 0; i < team.size; i++)
	{
		sum += team.team[i].getAbility();
	}
	return sum;
}

ElfTeam analyse(const ElfTeam* teams, int size)
{
	int i = 0;
	int max = sumAbilities(teams[i]);
	ElfTeam bestTeam;
	for (i = 1; i < size; i++)
	{
		if (sumAbilities(teams[i]) > max)
			bestTeam = teams[i];
	}
	return bestTeam;
}
void sort(ElfTeam& current)
{
	for (size_t i = 0; i < current.size - 1; i++)
	{
		for (size_t j = i + 1; j < current.size; j++)
		{
			if (strcmp(current.team[i].getName(), current.team[j].getName()) > 0 ||
				current.team[i].getAge() > current.team[j].getAge())
			{
				swap(current.team[i], current.team[j]);
			}
		}
	}

}
void sortTeamsP(ElfTeam** teams, int n = 3)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (strcmp(teams[i]->getTeamName(), teams[j]->getTeamName()) > 0)
			{
				swap(teams[i], teams[j]);
			}
		}
	}
}
void sortTeams(ElfTeam* teams, int n = 3)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (strcmp(teams[i].getTeamName(), teams[j].getTeamName()) > 0)
			{
				swap(teams[i], teams[j]);
			}
		}
	}
}

int main()
{
	//testing class Elf
	Elf e1;				//default c-tor
	e1.print();			//print()
	//testing setters
	e1.setName("Cersei");
	e1.setAge(42);
	e1.setAbility(34);
	e1.print();
	cout << e1 << endl;		 //operator <<

	Elf e2("Ned", 35, 12);	//param c-tor
	e2.print();
	cout << e2 << endl;		//operator <<

	e2 = e1;				// operator =
	cout << e2 << endl;

	Elf e3(e2);				//copy c-tor
	cout << e3 << endl;

	Elf e4("Bran", 7, 4),
		e5("Arya", 10, 5),
		e7("Sansa", 14, 10),
		e6 = e5;			  //operator =
	bool result = (e4 == e6); // operator ==
	bool reslt = (e6 == e5); // operator ==
	cout << boolalpha << result << endl;
	cout << boolalpha << reslt << endl;

	//testing class ElfTeam
	//Team A 
	Elf a1("Ned Stark", 44, 30),		// copy c-tor Elf
		a2("Kateline Stark", 40, 20),	// copy c-tor Elf
		a3("Robb Stark", 15, 15);		// copy c-tor Elf 
	ElfTeam a;							//default c-tor ElfTeam
	a.setName("Starks");				// testing setters 
	a.add(a1);							// add method
	a.add(a2);
	a.add(a3);
	cout << a;							//operator << for team 

//Team B
	Elf b1("Tywin Lanister", 60, 80),
		b2("Cersei Lanister", 42, 30),
		b3("Jamie Lanister", 42, 40);
	ElfTeam b;
	b.setName("Lanisters");
	b.add(b1);
	b.add(b2);
	b.add(b3);
	cout << b;

	//a = b;							//operator =
	//cout << a;						//operator <<
	ElfTeam group = a + b;				//operator = , operator +
	group.setName("NEVER HAPPEN");
	cout << group << endl;				// operator << 
	//a += b;							// operator += 
	cout << a << endl;

	// Team C 
	Elf c1("Rhagar Targarien", 230, 50),
		c2("Viserys Targerien", 190, 5),
		c3("Daenerys Targerien", 102, 345),
		c4("Daenerys Targerien", 12, 345),
		c5("Viserys Targerien", 123, 5);
	ElfTeam c;
	c.setName("Targerien");
	c.add(c1);
	c.add(c2);
	c.add(c3);
	c.add(c4);
	c.add(c5);

	ElfTeam teams[3];				// creating array of teams
	teams[0] = a;
	teams[1] = b;
	teams[2] = c;

	cout << "Calculating abilities" << endl;
	cout << a.getTeamName() << ": " << sumAbilities(a) << endl;
	cout << b.getTeamName() << ": " << sumAbilities(b) << endl;
	cout << c.getTeamName() << ": " << sumAbilities(c) << endl;

	ElfTeam theBest = analyse(teams, 3); // the best team
	cout << endl;
	cout << "THE BEST ABILITY: " << sumAbilities(theBest) << " of house: " << theBest.getTeamName() << endl;;
	cout << theBest << endl;

	bool rs = c < b;				//оператор <
	cout << boolalpha << rs << endl;

	sort(c);
	sort(b);
	sort(a);

	/*ElfTeam* tms[3];
	tms[0] = &a;
	tms[1] = &b;
	tms[2] = &c;

	sortTeamsP(tms,3);

	for (size_t i = 0; i < 3; i++)
	{
		cout << *tms[i] << endl;
	}
	*/
	ElfTeam ts[3];
	ts[0] = a;
	ts[1] = b;
	ts[2] = c;
	sortTeams(ts, 3);
	for (size_t i = 0; i < 3; i++)
	{
		cout << teams[i] << endl;
	}
	return 0;
}