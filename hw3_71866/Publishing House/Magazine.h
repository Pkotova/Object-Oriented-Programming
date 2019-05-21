#pragma once
#include "PrintEdition.h"
class Magazine : public PrintEdition
{
private:
	bool hasPosters;
	unsigned int numberOfInteviews;
public:
	Magazine();
	Magazine(double, unsigned int, double, const char*, bool, unsigned int);

	void setHasPosters(bool);
	void setNumbersOfInterviews(unsigned int);

	bool getHasPosters()const;
	unsigned int getNumberOfInterviews()const;

	double getSellPrice() const;
	void showInfo()const;

	~Magazine(); 
};

