#pragma once

class Stack
{
	char* arr;
	int size;
	int capacity;
public:

	Stack(int = 16);
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();

	char top() const;
	void pop();
	void push(char);
	int getSize() const;
	bool isEmpty() const;

private:
	void deleteStack();
	void copyStack(const Stack&);
	void resize();
};
