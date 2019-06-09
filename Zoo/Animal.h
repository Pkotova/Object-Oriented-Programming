#pragma once
class Animal
{
protected:

	char* species;
	int age;
	double food;
	bool isEndangered;

public:
	Animal();
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	Animal(const char*, int, double, bool);
	virtual ~Animal();

	void setSpecies(const char*);
	void setAge(int);
	void setFood(double);
	void setIsEndangered(bool);

	char* getSpecies()const;
	int getAge()const;
	double getFood()const;
	bool getIsEndangered()const;

	virtual double getFoodQuantity() const = 0;
	virtual int getRating() const = 0;
	virtual void print() const = 0;

	virtual Animal* clone() const = 0;
	bool operator==(const Animal& other) const;
};