#pragma once
#include "Fish.h"
using namespace std;


class Fisherman
{
private:
	char* name;
	Fish* caughtFish;
	int size;
	int capacity;

	void copy(const Fisherman&);
	void destroy();
	void resize();

public:
	Fisherman();
	Fisherman(const Fisherman&);
	Fisherman& operator=(const Fisherman&);
	Fisherman(const char*,Fish* , const int&, const int&);
	~Fisherman();

	void setName(const char*);
	char* getName()const;

	//Fish* getCaughtFish()const;

	void setSize(const int&);
	int  getSize()const;

	void setCapacity(const int&);
	int  getCapacity()const;

	void addFish(const Fish&);
	Fish biggestFish();
	double report();
	friend Fisherman& compareTo(Fisherman&, Fisherman&);

	friend ostream& operator<<(ostream&, const Fisherman&);

};

