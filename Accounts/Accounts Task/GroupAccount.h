#pragma once
#include "Account.h"
class GroupAccount :public Account
{
private:
	Account** usrs;
	int cloudStorage;
	int size;
	int capacity;

	void resizeUp();
	void resizeDown();
	void copy(const GroupAccount&);
	void destroy();


public:
	GroupAccount();
	GroupAccount(const GroupAccount&);
	GroupAccount& operator=(const GroupAccount&);
	~GroupAccount();

	void  setStorage();
	double getCloudStorage() override;
	bool isPremium() override;
	void showInfo() override;
	GroupAccount* clone() const override;

	bool isFull()const;

	void add(const Account&);
	void remove(const Account&);
};

