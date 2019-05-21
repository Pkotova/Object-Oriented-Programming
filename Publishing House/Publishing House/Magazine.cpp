#include "pch.h"
#include "Magazine.h"
#include "PrintEdition.h"
#include<iostream>
using namespace std;


Magazine::Magazine() : Magazine(0,0,0,"Default",true,0)
{}
Magazine::Magazine(double pricePerPage, unsigned int pages, double issue, 
	const char* name, bool hasPosters, unsigned int numberOfInterviews) : PrintEdition(pricePerPage,pages,issue,name)
{
	setHasPosters(hasPosters);
	setNumbersOfInterviews(numberOfInterviews);
}
void Magazine::setHasPosters(bool newHasPosters)
{
	this->hasPosters = newHasPosters;
}
void Magazine::setNumbersOfInterviews(unsigned int newNumbersOfInterviews)
{
	if (newNumbersOfInterviews >= 0) this->numberOfInteviews = newNumbersOfInterviews;
}
bool Magazine::getHasPosters()const
{
	return this->hasPosters;
}
unsigned int Magazine::getNumberOfInterviews()const
{
	return this->numberOfInteviews;
}
double Magazine::getSellPrice()const
{
	return (hasPosters) ? (getPrintPrice() + 1.5 + numberOfInteviews) 
						: (getPrintPrice() + numberOfInteviews);
}
void Magazine::showInfo()const
{
	cout << "Info for: " << this->name << endl;
	cout << "-----------------------------" << endl;
	cout << "Price per page: " << this->pricePerPage << " BNG" << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Issue: " << this->issue << "000" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Number of Interviews: " << this->numberOfInteviews << endl;
	cout << "Has posters: " << boolalpha << this->hasPosters << endl;
	cout << "Print price: " << getPrintPrice() << " BNG" << endl;
	cout << "Selling price: " << getSellPrice()<< " BNG" << endl;
	cout << endl;
}
Magazine::~Magazine()
{
	cout << " X - Magazine detructor - X" << endl;
}