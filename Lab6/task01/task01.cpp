// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class DynamicArray
{
private:
	int capacity;
	int size;
	int * arr;

	void resizeUp();
	void resizeDown();

	void copyOther(const DynamicArray&);
	void destroy();
public:
	//DynamicArray();
	DynamicArray(int = 8);
	DynamicArray(const DynamicArray&);
	
	DynamicArray& operator=(const DynamicArray&);
	void insert(int);
	void deleteElement(int);
	int operator[](const int&)const;
	int sizeOf()const;
	int getCapacity()const;
	~DynamicArray();
};
int DynamicArray::getCapacity()const
{
	return this->capacity;
}
DynamicArray& DynamicArray:: operator=(const DynamicArray& other) 
{
	if (this != &other)
	{
		destroy();
		copyOther(other);
	}
	return *this;
} 

void DynamicArray::insert(int element)
{
	if (this->size == this->capacity) resizeUp();
	this->arr[this->size] = element;
	this->size++;
}
void DynamicArray::deleteElement(int index)
{
	if (index < 0 || index >= this->size) return;
	for (int i = index; i < this->size - 1; i++)
	{
		this->arr[i] = this->arr[i + 1];
	}
	this->size--;
}
int DynamicArray::sizeOf() const
{
	return this->size;
}

DynamicArray::DynamicArray(int capacity) : arr(nullptr)
{
	int realLength = capacity > 0 ? capacity : 8;
	this->capacity = realLength;
	this->size = 0;
	this->arr = new int[this->capacity];
}
DynamicArray::DynamicArray(const DynamicArray& other)
{
	copyOther(other);
}
void DynamicArray::destroy()
{
	delete[] this->arr;
}
void DynamicArray::copyOther(const DynamicArray& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->arr = new int[capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = other.arr[i];
	}

}
int DynamicArray::operator[](const int & index)const
{
	if (index < 0 || index >= this->size) return -1;
	return this->arr[index];
}
void DynamicArray::resizeUp()
{
	this->capacity = this->capacity * 2;
	int* tempArray = new int[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		tempArray[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = tempArray;
}
void DynamicArray::resizeDown()
{

}
DynamicArray::~DynamicArray()
{
	destroy();
}
int main()
{
	DynamicArray a;
	cout << a.sizeOf();
    return 0;
}

