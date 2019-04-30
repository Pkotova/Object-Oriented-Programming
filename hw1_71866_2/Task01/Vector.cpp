#include "pch.h"
#include<iostream>
#include <initializer_list>
#pragma once

using namespace std;

template <typename T>
class Vector
{
private:
	T* vector;
	size_t vSize;
	size_t vCapacity;

	void resize();
	void copy(const Vector<T>&);
	void destroy();

public:

	template<typename T>
	class iterator 
	{
	private:
		T* element;
	public:
		iterator& operator++()
		{
			return (*this)++;
		}
		iterator operator++(int)
		{
			return ++(*this);
		}
		iterator& operator--()
		{
			return (*this)--;
		}
		iterator operator--(int)
		{
			return --(*this);
		}

	};

	Vector();									
	Vector(const Vector<T>&);					
	Vector<T>& operator=(const Vector<T>&);		
	~Vector();									

	Vector(size_t);								
	Vector(const T&, size_t);					
	Vector(initializer_list<T>list);			


	T& operator[](size_t);						
	T& at(size_t);								
	T& front();									
	T& back();									
	//iterator begin();
	//iterator end();
	bool empty();								
	size_t size()const;							
	void reserve(size_t);						
	size_t capacity()const;					
	void shrink_to_fit();						
	//iterator insert();						
	//iterator erase();							
	void push_back(const T&);					
	void pop_back();							
	void erase(const T&);		// does not work properly TODO 
	void erase_if(bool);

	void removeAt(size_t);
	void print();						//works
	//oт тези никой не работи <#
	friend bool operator==( Vector<T>&,  Vector<T>&);
	friend bool operator!=(const Vector<T>&, const Vector<T>&);
	friend bool operator<(const Vector<T>&, const Vector<T>&);
	friend bool operator>(const Vector<T>&, const Vector<T>&);
	friend bool operator<=(const Vector<T>&, const Vector<T>&);
	friend bool operator>=(const Vector<T>&, const Vector<T>&);
	friend void swap(Vector<T>&, Vector<T>&);
};

template <class T>
void Vector<T>::copy(const Vector& v)
{
	this->vSize = v.vSize;
	this->vCapacity = v.vCapacity;
	this->vector = new T[this->vCapacity];
	for (size_t i = 0; i < this->vSize; i++)
	{
		this->vector[i] = v.vector[i];
	}
}
template <class T>
void Vector<T>::resize()
{
	this->vCapacity = this->vCapacity * 2 + 1;
	T* temp = new T[this->vCapacity];
	for (size_t i = 0; i < this->vSize; i++)
	{
		temp[i] = this->vector[i];
	}
	destroy();
	this->vector = temp;
}
template<class T>
void Vector<T>::destroy()
{
	delete[] this->vector;
}
template <class T>
Vector<T>::Vector()
{
	this->vCapacity = 8;
	this->vSize = 0;
	this->vector = new T[this->vCapacity];
}
template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	copy(v);
}
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this != &v)
	{
		destroy();
		copy(v);
	}
	
	return *this;
}
template <class T>
Vector<T>::Vector(size_t newCapacity)
{
	this->vSize = 0;
	this->vCapacity = newCapacity;
	this->vector = new T[newCapacity];
}
template <class T>
Vector<T>::Vector(const T& element,size_t copies)
{
	this->vSize = copies;
	this->vCapacity = 100;
	this->vector = new T[copies];
	for (size_t i = 0; i < this->vSize; i++)
	{
		this->vector[i] = element;
	}
}
template<class T>
Vector<T>::Vector(initializer_list<T> l)
{
	for (auto i = l.begin(); i < l.end(); i++)
	{
		push_back(*i);
	}
}
template <class T>
T& Vector<T>::operator[](size_t index)
{
	return this->vector[index];
}
template <class T>
T& Vector<T>::at(size_t index)
{
	if (index >= 0 && index <= this->vSize - 1) 
	 return this->vector[index];
}
template <class T>
T& Vector<T>::front()
{
	return this->vector[0];
}
template <class T>
T& Vector<T>::back()
{
	return this->vector[this->vSize - 1];
}
template <class T>
bool Vector<T>::empty()
{
	return (this->vSize == 0);
}
template <class T>
void Vector<T>::reserve(size_t newCapacity)
{
	T* temp = new T[newCapacity];
	this->vCapacity = newCapacity;
	for (size_t i = 0; i < newCapacity; i++)
	{
		temp[i] = this->vector[i];
	}
	destroy();
	this->vector = temp;

}
template <class T>
void Vector<T>::shrink_to_fit()
{
	if (this->vCapacity > vSize)
	{
		vCapacity = vSize;
	}
}
template <class T>
void Vector<T>::push_back(const T& element)
{
	if (this->vCapacity == this->vSize)
	{
		resize();
	}
	this->vector[vSize] = element;
	vSize++;
}
template <class T>
void Vector<T>::pop_back()
{
	vSize--;
}
template <class T>
void Vector<T>::removeAt(size_t index)
{
	if (index < 0 || index > this->vSize - 1) return;

	for (int i = index; i < this->vSize; ++i) 
	{
		this->vector[i] = this->vector[i + 1];
	}
	this->vSize--;

}
template <class T>
void Vector<T>::erase(const T& current)
{
	for (int i = 0; i <= this->vSize; ++i)
	{
		if (this->vector[i] == current)
		{
			removeAt(i);
		}
	}
}
template <class T>
void Vector<T>::erase_if(bool predicate)
{
	for (int i = 0; i < this->vSize; i++)
	{
		if (predicate)
		{
			removeAt(i);
		}
	}
}
template <class T>
void Vector<T>::print()
{
	for (size_t i = 0; i < this->vSize; i++)
	{
		cout << this->vector[i] << endl;
	}
}
template <class T>
size_t Vector<T>::size()const
{
	return this->vSize;
}

template <class T>
size_t Vector<T>::capacity()const
{
	return this->vCapacity;
}

template <class T>
bool operator==( Vector<T>& v1,  Vector<T>& v2)
{
	bool result = true;
	if (v1.size() == v2.size())
	{
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1.vector[i] != v2.vector[i])
			{
				return !result;
			}
		}
	}
	else return !result;
}
template <class T>
bool operator!=(const Vector<T>&, const Vector<T>&)
{

}
 template <class T>
 bool operator<(const Vector<T>&, const Vector<T>&)
 {

 }
 template <class T>
 bool operator>(const Vector<T>&, const Vector<T>&)
 {

 }
 template <class T>
 bool operator<=(const Vector<T>&, const Vector<T>&)
 {

 }

 template <class T>
 bool operator>=(const Vector<T>&, const Vector<T>&)
 {

 }
 template <class T>
 void swap(Vector<T>&, Vector<T>&)
 {

 }
template <class T>
Vector<T>::~Vector()
{
	destroy();
}
