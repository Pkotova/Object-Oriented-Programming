#pragma once
#include"PrintEdition.h"
class Book : public PrintEdition
{
private: 
	char* authorName;
	bool hasHardCovers;
	unsigned int year;
public:
	Book();
	Book(const Book&);
	Book& operator=(const Book&);
	Book(double, unsigned int, double, const char*,
		const char*, bool, unsigned int);
	
	void setAuthorName(const char*);
	void setHasHardCovers(bool);
	void setYear(unsigned int);

	char* getAuthorName()const;
	bool getHasHardCovers()const;
	unsigned int getYear()const;

	double getSellPrice()const;
	void showInfo() const;
	~Book();
};

