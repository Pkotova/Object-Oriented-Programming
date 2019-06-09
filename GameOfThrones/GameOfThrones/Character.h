#pragma once
#include<ostream>
class Character
{
protected:

	char* fullName;
	unsigned int age;
	char sex;

public:
	Character();
	Character(const char*, unsigned int, char);
	Character(const Character&);
	Character& operator=(const Character&);
	virtual ~Character();


	void setFullName(const char*);
	void setAge(int);
	void setSex(char);

	char* getFullName()const;
	unsigned int getAge()const;
	char getSex()const;

	void show() const;
	virtual int getScore() const = 0;
	virtual void print() const = 0;
	
	virtual Character* clone() const = 0;
	bool operator==(const Character& other) const;
};

