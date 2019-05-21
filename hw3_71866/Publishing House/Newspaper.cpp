#include "pch.h"
#include<iostream>
#include<cstring>
#include "Newspaper.h"

using namespace std;

Newspaper::Newspaper() : Newspaper(0,0,0,"Default","01.01.2000",0)
{}
Newspaper::Newspaper(double pricePerPage, unsigned int pages, double issue,
	const char* name, const char printDate[40], unsigned int ads)
	: PrintEdition(pricePerPage, pages, issue, name)
{
	setPrintDate(printDate);
	setAds(ads);
}
void Newspaper::setPrintDate(const char newPrintDate[40])
{
	if(newPrintDate != NULL ) strcpy_s(this->printDate, 40, newPrintDate);
}
void Newspaper::setAds(unsigned int newAds)
{
	if(newAds >= 0) this->ads = newAds;
}
char* Newspaper::getPrintDate()
{
	return this->printDate;
}
unsigned int Newspaper::getAds()const
{
	return this->ads;
}
double Newspaper::getSellPrice()const
{
	return (getPrintPrice() + (this->ads * (-0.05)));
}
void Newspaper::showInfo()const
{
	cout << "Info for: " << this->name << endl;
	cout << "-----------------------------" << endl;
	cout << "Price per page: " << this->pricePerPage << " BNG" << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Issue: " << this->issue << "000" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Print date: " << this->printDate << endl;
	cout << "Ads: " << this->ads << endl;
	cout << "Print price: " << getPrintPrice() << " BNG" << endl;
	cout << "Selling price: " << getSellPrice()<< " BNG" << endl;

	cout << endl;
}
Newspaper::~Newspaper()
{
	cout << " X - Newspaper detructor - X" << endl;
}