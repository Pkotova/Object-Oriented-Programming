#include "pch.h"
#include "ServerFarm.h"
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void ServerFarm::resizeUp()
{
	this->capacity *= 2;
	WebServer* temp = new WebServer[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->farm[i];
	}
	delete[] this->farm;
	this->farm = temp;
}

void ServerFarm::resizeDown()
{
	this->capacity /= 2;
	WebServer* temp = new WebServer[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->farm[i];
	}
	delete[] this->farm;
	this->farm = temp;
}

void ServerFarm::copy(const ServerFarm &other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->farm = new WebServer[this->capacity];
	for (size_t i = 0; i < this->capacity; i++)
	{
		this->farm[i] = other.farm[i];
	}
}

void ServerFarm::destroy()
{
	delete[] this->farm;
}

ServerFarm::ServerFarm()
{
	this->size = 0;
	this->capacity = 8;
	this->farm = new WebServer[capacity];
}

ServerFarm::ServerFarm(const ServerFarm &other)
{
	copy(other);
}

ServerFarm & ServerFarm::operator=(const ServerFarm &other)
{
	if (this != &other)
	{
		copy(other);
		destroy();
	}
	return *this;
}


ServerFarm::~ServerFarm()
{
	destroy();
}

int ServerFarm::countInNetwork(const int fix)
{
	int temp = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		if ((farm[fix]) ^= (farm[i]))
		{
			temp++;
		}
			
	}
	return temp;
}

void ServerFarm::findMaxNetwork()
{
	int max = 0;
	int temp[4] = { 0,0,0,0 };
	for (int i = 0; i < this->size; i++)
	{
		if (max < countInNetwork(i))
		{
			max = countInNetwork(i);
			for (int j = 0; j < 3; j++)
			{
				temp[j] = this->farm[i].getIP()[j];
			}
		}
	}
	for (size_t i = 0; i < 4; i++)
	{
		cout << temp[i];
		if (i < 3)
		{
			cout << ".";
		}
	}
}


ServerFarm & ServerFarm::sort()
{
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if ((*&farm[i] < *&farm[j]))
			{
				swap(farm[i], farm[j]);
			}
		}
	}
	return *this;
}


ServerFarm & ServerFarm::operator-=(const int _ip[4])
{
	removeServer(_ip);
	return *this;
}

ServerFarm& ServerFarm::addServer(const WebServer &other)
{
	if (isFull())
		resizeUp();
	this->farm[this->size] = other;
	this->size++;
	return *this;
}


void ServerFarm::removeServer(const int ip[4])
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->farm[i] == ip)
		{
			this->farm[i] = this->farm[--size];
			if (this->size < this->capacity / 2)
				resizeDown();
			break;
		}
	}
}

void ServerFarm::print()
{
	cout << "--PRINTING--\n";
	for (int i = 0; i < this->size; i++)
	{
		this->farm[i].print();
	}
}

bool ServerFarm::isFull()
{
	return this->capacity==this->size;
}
