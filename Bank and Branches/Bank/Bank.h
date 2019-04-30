#pragma once
#include"Branch.h"

class Bank {
private:
	Branch* branches;
	int wonClients;
	int lostClients;
public:

	Branch& operator[](const int&);
	int getWorkCoeff() const;

	Bank(Branch*);
	Bank();
	Bank(const Bank&);

	Bank& operator=(Bank&);
	~Bank();
	friend Bank& race(Bank&,Bank&);

	Bank operator+(Bank&);
};
