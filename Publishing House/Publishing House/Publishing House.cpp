// Petya Kotova, f.n. 71866, gr2.

#include "pch.h"
#include <iostream>
#include "PrintEdition.h"
#include "Newspaper.h"
#include "Magazine.h"
#include "Book.h"
using namespace std;
int main()
{
	/*  EACH NEWSPAPER HAS:
		price per page,
		pages,
		issue (thousands),
		name,
		print date,
		number of ads;
	*/
	Newspaper* n1 = new Newspaper(0.1, 10, 3, "TRUD","20.05.2019",10);
	Newspaper* n2 = new Newspaper(0.1, 15, 5, "TELEGRAF", "19.05.2019", 8);

	/*  EACH MAGAZINE HAS:
		price per page,
		pages,
		issue (thousands),
		name,
		if it has posters,
		numbers of inteviews
	*/
	
	Magazine* m1 = new Magazine(0.02, 20, 1, "BRAVO", true, 4);
	Magazine* m2 = new Magazine(0.02, 30, 1.5, "GRAZIA", false, 7);

	/*  EACH BOOK HAS:
		price per page,
		pages,
		issue (thousands),
		name,
		author's name,
		if it has hard covers,
		year of publishing
	*/
	Book* b1 = new Book(0.02, 200, 0.6, "The Little Prince", "Antoine de Saint-Exupéry", false, 1943);
	Book* b2 = new Book(0.01, 500, 4, "A Song of Ice and Fire", "George R. R. Martin", false, 1996);
		
	//show info 
	n1->showInfo();
	n2->showInfo();

	m1->showInfo();
	m2->showInfo();

	b1->showInfo();
	b2->showInfo();

	//freeing up the using memory
	cout << " DESTROYING " << endl;
	delete n1;
	delete n2;
	delete m1;
	delete m2;
	delete b1;
	delete b2;

	// деструкторите в класовете Magazine и Newspaper, не са необходими, защото
	// не използвам динамично заделяне памет за нито една от член-данните.
	// имплементирала съм ги за да се отпечатат съобщение при разрушаване на инстация от класа. 
}


