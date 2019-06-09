#pragma once
#include"Animal.h"
class Zoo
{
private:

	char* location;
	Animal** animals;

	int size;
	int capacity;

	void resizeUp();
	void resizeDown();

	void copy(const Zoo&);
	void destroy();

public:
	Zoo();
	Zoo(const Zoo&);
	Zoo& operator=(const Zoo&);
	Zoo(const char*);
	~Zoo();

	int getSize()const;
	int getCapacity()const;

	void setLocation(const char*);
	char* getLocation()const;

	bool isFull()const;
	void addAnimal(const Animal&);
	void removeAnimal(const Animal&);

	void showAnimals()const;
	double getTicketPrice()const;
};
