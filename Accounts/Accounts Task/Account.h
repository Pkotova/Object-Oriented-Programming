#pragma once
class Account
{
protected:
	char* email;
	bool type;
public:
	Account();
	Account(const Account&);
	Account(const char*, bool);
	Account& operator=(const Account&);
	virtual ~Account();

	virtual double getCloudStorage() = 0;
	virtual bool isPremium() = 0;
	virtual void showInfo() = 0;
	virtual Account* clone() const = 0;
	
	void setEmail(const char*);
	char* getEmail() const;
	bool operator==(const Account&);
};

