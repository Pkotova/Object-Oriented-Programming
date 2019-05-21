#pragma once
class PrintEdition
{
protected:
    double pricePerPage;
	unsigned int pages;
	double issue;
	char* name;
public:
	PrintEdition();
	PrintEdition(const PrintEdition&);
	PrintEdition(double, unsigned int, double, const char* );
	PrintEdition& operator=(const PrintEdition&);

	void setPricePerPage(double);
	void setPages(unsigned int);
	void setIssue(double);
	void setName(const char*);

	double getPricePerPage()const;
	unsigned int getPages()const;
	double getIssue()const;
	char* getName()const;

	virtual double getPrintPrice()const;
	virtual double getSellPrice() const  = 0;
	virtual void showInfo() const = 0;
	virtual ~PrintEdition();
};

