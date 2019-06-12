#include "pch.h"
#include "GroupAccount.h"
#include<iostream>
using namespace std;

void GroupAccount::resizeUp()
{
	this->capacity *= 2;
	Account** temp = new Account*[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->usrs[i]->clone();
	}
	delete[] this->usrs;
	this->usrs = temp;
}
void GroupAccount::resizeDown()
{
	this->capacity /= 2;
	Account** temp = new Account*[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->usrs[i]->clone();
	}
	delete[] this->usrs;
	this->usrs = temp;
}
void GroupAccount::copy(const GroupAccount &other)
{
	setEmail(other.email);
	this->type = other.type;
	this->size = other.size;
	
	this->capacity = other.capacity;
	this->usrs = new Account*[this->capacity];
	for (size_t i = 0; i < size; i++)
	{
		this->usrs[i] = other.usrs[i]->clone();
	}
	setStorage();
}

void GroupAccount::destroy()
{
	for (size_t i = 0; i < size; i++)
	{
		delete this->usrs[i];
	}
	delete[] this->usrs;
}

void GroupAccount::setStorage()
{
	cout << "ZDR" << endl;

	int premiumStorage = 0;
	for (int i = 0; i < this->size; i++)
	{

		if (this->usrs[i]->isPremium())
		{
			premiumStorage += this->usrs[i]->getCloudStorage();
		}
	}

	this->cloudStorage = (premiumStorage / 2);
}

GroupAccount::GroupAccount():Account()
{
	this->cloudStorage = 0;
	this->size = 0;
	this->capacity = 8;
	this->usrs = new Account*[this->capacity];
}

GroupAccount::GroupAccount(const GroupAccount &other)
{
	copy(other);
}

GroupAccount & GroupAccount::operator=(const GroupAccount& other)
{
	if (this != &other)
	{
		Account::operator=(other);
		destroy();
		copy(other);
	}
	return *this;
}

GroupAccount::~GroupAccount()
{
	destroy();
}

double GroupAccount::getCloudStorage()
{
	//return this->cloudStorage;
	int premiumStorage = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (this->usrs[i]->isPremium())
		{
			premiumStorage += this->usrs[i]->getCloudStorage();
		}
	}
	return (premiumStorage / 2);
}

bool GroupAccount::isPremium()
{
	int premium = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (this->usrs[i]->isPremium())
		{
			premium ++;
		}
	}

	return (premium >= this->size / 2);
}
void GroupAccount::showInfo()
{
	for (int i = 0; i < this->size; i++)
	{

		this->usrs[i]->showInfo();
	}
	cout << endl;
	cout << "Is premium group: " << isPremium() << endl;
	cout << "Cloud storage: " << getCloudStorage() << endl;
}
GroupAccount * GroupAccount::clone() const
{
	return new GroupAccount(*this);
}

bool GroupAccount::isFull() const
{
	return this->size == this->capacity;
}

void GroupAccount::add(const Account & other)
{
	if (isFull()) resizeUp();
	this->usrs[size++] = other.clone();
}
void GroupAccount::remove(const Account& other)
{
	for  (int i = 0; i < this->size;i++)
	{
		if (*(this->usrs[i]) == other)
		{
			delete this->usrs[i];
			usrs[i] = usrs[--size];
			if (this->size < (this->capacity) / 2)
			{
				resizeDown();
			}
			break;
		}
	}
}