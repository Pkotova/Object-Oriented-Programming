// Task.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Animal.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Zoo.h"
#include <iostream>
using namespace std;

int main()
{
	Carnivore c1("Tiger", 10, 10, true, false),
			  c2("Pantera", 5, 2, true, false),
			  c3("Lion", 7, 8, true, false);

	Herbivore h1("Horse", 4, 2, false, true),
			  h2("Goat", 3, 5, false, true),
		      h3("Cow", 1, 15, false, false);
	Zoo z;
	z.setLocation("Sofia");

	z.addAnimal(c1);
	z.addAnimal(c2);
	z.addAnimal(c3);
	z.addAnimal(h1);
	z.addAnimal(h2);
	z.addAnimal(h3);
	//z.showAnimals();

	z.removeAnimal(c2);
	z.showAnimals();
	//cout <<"Zoo capacity: " <<z.getCapacity() << endl;
	//cout << "Animals: " << z.getSize() << endl;

    return 0;
}