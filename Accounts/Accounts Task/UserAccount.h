#pragma once
#include "Account.h"
class UserAccount :public Account
{
	int storage;
public:
	UserAccount();
	UserAccount(const char*, bool);
	~UserAccount();

	double getCloudStorage() override;
	bool isPremium() override;
	void showInfo() override;
	UserAccount* clone() const override;
};

