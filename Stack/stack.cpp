// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "stack.h"

#include <iostream>
#include <cassert>

Stack::Stack(int capacity)
{
	this->arr = new char[capacity];
	this->size = 0;
	this->capacity = capacity;
}

Stack::Stack(const Stack& other)
{
	copyStack(other);
}

Stack& Stack::operator=(const Stack& other)
{
	if (this != &other)
	{
		deleteStack();
		copyStack(other);
	}

	return *this;
}

Stack::~Stack()
{
	deleteStack();
}

void Stack::deleteStack()
{
	delete[] arr;
}

void Stack::copyStack(const Stack& other)
{
	this->arr = new char[other.capacity];
	this->size = other.size;
	this->capacity = other.capacity;

	for (int i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

char Stack::top() const
{
	assert(!isEmpty());
	return this->arr[size - 1];
}

void Stack::pop()
{
	assert(!isEmpty());
	this->size--;
}

int Stack::getSize() const
{
	return size;
}

bool Stack::isEmpty() const
{
	return this->size == 0;
}

void Stack::push(char value)
{
	if (size >= capacity)
	{
		resize();
	}

	this->arr[size] = value;
	size++;
}

void Stack::resize()
{
	char* newArr = new char[2 * capacity];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = this->arr[i];
	}
	delete[] arr;
	this->capacity = 2 * capacity;
	this->arr = newArr;
}