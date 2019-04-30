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

	class iterator
	{
	private:
		T* ptr;
		size_t index;
	public:

		iterator()
		{
			this->ptr = nullptr;
			this->index = -1;
		}
		iterator(T* _ptr, size_t _index)
		{
			this->ptr = _ptr;
			this->index = index;
		}
		iterator(const iterator& other)
		{
			this->ptr = other.ptr;
			this->index = other.index;
		}
		iterator& operator=(const iterator& other)
		{
			if (this != other)
			{
				delete[] this->ptr;
				this->index = other.index;
				this->ptr = other.ptr;

			}
		}
		~iterator()
		{
			delete[] this->ptr;
		}

		T& operator*()
		{
			return (*ptr)[index];
		}
		const T& operator*() const
		{
			return (*ptr)[index];
		}
		T* operator->()
		{
			return &((*ptr)[index]);
		}
		const T* operator->() const
		{
			return &((*ptr)[index]);
		}

		bool operator<(const iterator& other)
		{
			return this->index < other.index;
		}
		bool operator>(const iterator& other)
		{
			return this->index > other.index;
		}
		bool operator<=(const iterator& other)
		{
			return this->index <= other.index;
		}
		bool operator>=(const iterator& other)
		{
			return this->index >= other.index;
		}
		bool operator==(const iterator& other)
		{
			return this->index == other.index;
		}
		bool operator!=(const iterator& other)
		{
			return this->index != other.index;
		}

		iterator& operator++()
		{
			++index;
			return *this;
		}
		iterator operator++(int)
		{
			iterator iter(*this);
			++index;
			return iter;
		}
		iterator& operator--()
		{
			--index;
			return *this;
		}
		iterator operator--(int)
		{
			iterator iter(*this);
			--index;
			return iter;
		}

		iterator& operator+=(int n)
		{
			index += n;
			return *this;
		}
		iterator& operator-=(int n)
		{
			index -= n;
			return *this;
		}

		iterator operator+(int n)
		{
			iterator iter(*this);
			return iter += n;
		}
		iterator operator-(int n)
		{
			iterator iter(*this);
			return iter -= n;
		}

	};

	Vector();				
	Vector(size_t);
	Vector(const T&, size_t);
	Vector(const Vector<T>&);			
	Vector(initializer_list<T>list);
	Vector<T>& operator=(const Vector<T>&);		
	~Vector();								

	T& operator[](size_t);						
	T& at(size_t);								
	T& front();									
	T& back();									
	iterator begin();
	iterator end();
	bool empty();								
	size_t size()const;							
	void reserve(size_t);						
	size_t capacity()const;					
	void shrink_to_fit();						
	iterator insert(int, const T&);
	iterator erase(size_t);							
	void push_back(const T&);					
	void pop_back();							
	void erase(const T&);		// does not work properly TODO 
	void erase_if(bool);
	void removeAt(size_t);
	void print();						//works
	void swap(Vector<T>& other);
	bool operator>(const Vector<T>& other);
	bool operator<(const Vector<T>& other);
	bool operator>=(const Vector<T>& other);
	bool operator<=(const Vector<T>& other);
	bool operator==(const Vector<T>& other);
	bool operator!=(const Vector<T>& other);
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
	if (index < this->vSize) return this->vector[index];
	else return this->vector[this->vSize - 1];
}
template <class T>
T& Vector<T>::front()
{
	return this->vector[0];
}

//template<class T> typename Vector<T>::iterator Vector<T>::begin(){}
//template<typename T> typename Vector<T>::iterator Vector<T>::end(){}

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
	if (this->vCapacity > this->vSize)
	{
		this->vCapacity = this->vSize;
		T* temp = new T[vCapacity];
		for (int i = 0; i < vSize; i++)
		{
			temp[i] = this->vector[i];
		}
		delete[] this->vector;
		this->vector = temp;
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
template<class T>
typename Vector<T>::iterator Vector<T>::insert(int position, const T & element)
{
	if (this->vSize == this->vCapacity) this->resize();
	T* temp = new T[vCapacity];
	for (int i = 0; i < position; i++)
	{
		temp[i] = this->vector[i];
	}
	temp[position] = element;
	for (int i = position + 1; i < vSize + 1; i++)
	{
		temp[i] = this->vector[i - 1];
	}
	this->vSize++;
	delete[] this->vector;
	this->vector = temp;
	return Vector<T>::iterator
	{
		this, position
	};
}
template<typename T>
typename Vector<T>::iterator Vector<T>::erase(size_t position)
{
	for (int i = position; i < this->vSize - 1; i++)
	{
		this->vector[i] = this->vector[i + 1];
	}
	this->vSize--;
	return Vector<T>::iterator{ this, position };
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
bool Vector<T>::operator==(const Vector<T>& other)
{
	for (int i = 0; i < this->vSize; i++)
	{
		if (this->vector[i] != other.vector[i]) return false;
	}
	return true;
}
template<class T>
bool Vector<T>::operator!=(const Vector<T>& other)
{
	return !(this == &other);
}

template<typename T>
bool Vector<T>::operator>(const Vector<T>& other)
{
	for (int i = 0; i < this->vSize; i++)
	{
		if (this->vector[i] <= other.vector[i]) return false;
	}
	return true;
}

template<class T>
bool Vector<T>::operator<(const Vector<T>& other)
{
	for (int i = 0; i < this->vSize; i++)
	{
		if (this->vector[i] >= other.vector[i]) return false;
	}
	return true;
}

template<class T>
bool Vector<T>::operator>=(const Vector<T>& other)
{
	return !(this<&other);
}

template<class T>
bool Vector<T>::operator<=(const Vector<T>& other)
{
	return !(this>&other);
}
 template <class T>
 void Vector<T>::swap(Vector<T>& other)
 {
	 Vector<T> temp = this;
	 this = &other;
	 other = temp;
 }

template <class T>
Vector<T>::~Vector()
{
	destroy();
}
