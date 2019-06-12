#include "pch.h"
#include "UserAccount.h"
#include <iostream>
using namespace std;

UserAccount::UserAccount() :Account()
{
	this->storage = 15;
}

UserAccount::UserAccount(const char* em, bool t) : Account(em, t)
{
	this->storage = (isPremium()) ? 150 : 15;
}

UserAccount::~UserAccount()
{}

double UserAccount::getCloudStorage()
{
	return this->storage = (isPremium()) ? 150 : 15;
}

bool UserAccount::isPremium()
{
	return this->type;
}

void UserAccount::showInfo()
{
	Account::showInfo();
	cout << "Storage: " << this->storage << endl;
}

UserAccount * UserAccount::clone() const
{
	return new UserAccount(*this);
}
