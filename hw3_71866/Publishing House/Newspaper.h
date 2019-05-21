#pragma once
#include "PrintEdition.h"
class Newspaper : public  PrintEdition
{
private:
	char printDate[40];
	unsigned int ads;
public:

	Newspaper();
	Newspaper(double, unsigned int, double, const char*,const char[40], unsigned int);

	void setPrintDate(const char[40]);
	void setAds(unsigned int);

	char* getPrintDate();
	unsigned int getAds()const;

	double getSellPrice() const;
	void showInfo() const;

	~Newspaper();
};

