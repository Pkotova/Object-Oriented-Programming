#include "pch.h"
#include "Account.h"
#include <cstring>
#include <iostream>
using namespace std;

Account::Account() : email(nullptr)
{
	type = false;
	setEmail("defalut@gmail.com");
}

Account::Account(const Account &other): email(nullptr)
{
	this->type = other.type;
	setEmail(other.email);
}

Account::Account(const char* _em, bool _pre): email(nullptr)
{
	this->type = _pre;
	setEmail(_em);
}

Account & Account::operator=(const Account &other)
{
	if (this != &other)
	{
		this->type = other.type;
		setEmail(other.email);
	}
	return *this;
}


Account::~Account()
{
	delete[] this->email;
}

void Account::setEmail(const char* em)
{
	if (em != nullptr)
	{
		delete[] this->email;
		this->email = new char[strlen(em)+1];
		strcpy_s(this->email, strlen(em)+1, em);
	}
}

char * Account::getEmail() const
{
	return this->email;
}

bool Account::operator==(const Account &other)
{
	return (strcmp(this->email, other.email) == 0) && (this->type == other.type);
}

void Account::showInfo()
{
	cout << "Email: " << this->email<<endl;
	cout << "Is premium: " << boolalpha << this->type<<endl;
}