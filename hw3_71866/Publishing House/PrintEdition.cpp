#include "pch.h"
#include "PrintEdition.h"
#include<cstring>
#include <iostream>

using namespace std;

PrintEdition::PrintEdition() : PrintEdition(0,0,0,"Dafault")
{}
PrintEdition::PrintEdition(const PrintEdition& other)
	: PrintEdition(other.pricePerPage,other.pages,other.issue,other.name)
{}
PrintEdition::PrintEdition(double pricePerPage, unsigned int pages, double issue, const char* name) : name(nullptr)
{
	setPricePerPage(pricePerPage);
	setPages(pages);
	setIssue(issue);
	setName(name);
}
PrintEdition& PrintEdition::operator=(const PrintEdition& other)
{
	if (this != &other)
	{
		setPricePerPage(other.pricePerPage);
		setPages(other.pages);
		setIssue(other.issue);
		setName(other.name);
	}
	return *this;
}
void PrintEdition::setPricePerPage(double newPricePerPage)
{
	if (newPricePerPage >= 0) this->pricePerPage = newPricePerPage;
}
void PrintEdition::setPages(unsigned int newPages)
{
	if (newPages >= 0) this->pages = newPages;
}
void PrintEdition::setIssue(double newIssue)
{
	if (newIssue >= 0) this->issue = newIssue;
	
}
void PrintEdition::setName(const char* newName)
{
	if (newName != nullptr)
	{
		delete[] name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}
double PrintEdition::getPricePerPage()const
{
	return this->pricePerPage;
}
unsigned int PrintEdition::getPages()const
{
	return this->pages;
}
double PrintEdition::getIssue()const
{
	return this->issue;
}
char* PrintEdition::getName()const
{
	return this->name;
}
double PrintEdition::getPrintPrice()const
{
	return (this->pages * this->pricePerPage);
}
double PrintEdition::getSellPrice()const
{
	return getPrintPrice();
}
void PrintEdition::showInfo()const
{
	cout << "Price per page: " << this->pricePerPage << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Issue: " << this->issue << "000" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Selling price: " << getSellPrice() << endl;
	cout << "Print price: " << getPrintPrice() << endl;
}
PrintEdition::~PrintEdition()
{
	delete[] this->name;
	cout << " X - Print Edition detructor - X" << endl;
}
