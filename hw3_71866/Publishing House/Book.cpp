#include "pch.h"
#include "Book.h"
#include "PrintEdition.h"
#include<cstring>
#include<iostream>
using namespace std;

Book::Book() : Book(0,0,0,"Default","Default",false,2000)
{}
Book::Book(const Book& other)
	: Book(other.pricePerPage, other.pages, other.issue, other.name, other.authorName, other.hasHardCovers, other.year)
{}
Book::Book(double pricePerPage, unsigned int pages, double issue, const char* name,
	const char* authorName, bool hasHardCovers, unsigned int year) : PrintEdition(pricePerPage, pages, issue, name)
{
	setAuthorName(authorName);
	setHasHardCovers(hasHardCovers);
	setYear(year);
}
Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		PrintEdition::operator=(other);
		delete[] authorName;
		setAuthorName(other.authorName);
		setHasHardCovers(other.hasHardCovers);
		setYear(other.year);
	}
	return *this;
}
void Book::setAuthorName(const char* newAuthorName)
{
	if (newAuthorName != nullptr)
	{
		delete[] this->authorName;
		this->authorName = new char[strlen(newAuthorName) + 1];
		strcpy_s(this->authorName, strlen(newAuthorName) + 1, newAuthorName);
 	}
}
void Book::setHasHardCovers(bool newHasHardCovers)
{
	this->hasHardCovers = newHasHardCovers;
}
void Book::setYear(unsigned int newYear)
{
	if(newYear < 2019) this->year = newYear;
}
char* Book::getAuthorName()const
{
	return this->authorName;
}
bool Book::getHasHardCovers()const
{
	return this->hasHardCovers;
}
unsigned int Book::getYear()const
{
	return this->year;
}
double Book::getSellPrice()const
{
	return ((hasHardCovers) ? (getPrintPrice() + 5) : (getPrintPrice() + 2.5));
}
void Book::showInfo()const
{
	cout << "Info for: " << this->name << endl;
	cout << "-----------------------------" << endl;
	cout << "Price per page: " << this->pricePerPage << " BNG" << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Issue: " << this->issue << "000" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Author's name: " << this->authorName << endl;
	cout << "Has hard covers: " << boolalpha << this->hasHardCovers << endl;
	cout << "Year of publishing: " << this->year << endl;
	cout << "Print price: " << getPrintPrice() << " BNG"<< endl;
	cout << "Selling price: " << getSellPrice()<< " BNG"<< endl;
	cout << endl;
}
Book::~Book()
{
	delete[] authorName;
	cout << " X - Book detructor - X" << endl;
}
