#include "Bank.h"
#include <iostream>

Branch & Bank::operator[](const int &index)
{
	return this->branches[index];
}

int Bank::getWorkCoeff() const
{
	double sum = 0;
	for (int i = 0; i < 10; ++i) {
		sum += (double)(this->branches[i].getWorkCoeff());
	}
	return sum/10;
}

Bank::Bank(Branch* branches)
{
	this->branches = new Branch[10];
	for (int i = 0; i < 10; i++) {
		this->branches[i] = branches[i];
	}
}

Bank::Bank()
{
	this->branches = new Branch[10];
}

Bank::Bank(const Bank & other)
{
	this->branches = new Branch[10];
	for (int i = 0; i < 10; ++i) {
		this->branches[i] = other.branches[i];
	}
}

Bank & Bank::operator=(Bank & other)
{
	if (this != &other) {
		delete[] this->branches;
		this->branches = new Branch[10];
		for (int i = 0; i < 10; ++i) {
			this->branches[i] = other.branches[i];
		}
	}
	return *this;
}

Bank::~Bank()
{
	delete[] branches;
}

Bank Bank::operator+(Bank & other)
{
	for(int i=0;i<9;i++){
		for (int j = i+1; j < 10; j++) {
			if (branches[i].getWorkCoeff() < branches[j].getWorkCoeff()) std::swap(branches[i], branches[j]);
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (other.branches[i].getWorkCoeff() < other.branches[j].getWorkCoeff()) std::swap(other.branches[i], other.branches[j]);
		}
	}

	Branch* newBranches = new Branch[10];

	int count1 = 0;
	int count2 = 0;
	int count = 0;

	while (count1 + count2 < 11) {
		if (branches[count1].getWorkCoeff() > branches[count2].getWorkCoeff()) {
			newBranches[count] = branches[count1];
			count++;
			count1++;
		}
		else {
			newBranches[count] = other.branches[count2];
			count++;
			count2++;
		}
	}

	for (int i = 0; i < 10; i++) {
		newBranches[i].setId(i);
	}

	return Bank(newBranches);
}

Bank& race(Bank & first,Bank & second)
{
	if (first.getWorkCoeff() >= second.getWorkCoeff()) {
		std::cout<<"First bank wins the client";
		first.wonClients++;
		second.lostClients++;
		return first;
	}
	else {
		std::cout << "Second bank wins the client";
		first.lostClients++;
		second.lostClients--;
		return second;
	}
}

