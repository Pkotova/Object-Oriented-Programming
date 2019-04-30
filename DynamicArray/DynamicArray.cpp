#include "DynamicArray.h"
#include <iostream>


DynamicArray::DynamicArray()
{
    std::cout << "Default c-tor." << std::endl;

    capacity = 8;
    size = 0;
    arr = new int[capacity];
}

DynamicArray::DynamicArray(int initialCapacity)
{
    std::cout << "Param. c-tor" << std::endl;

    capacity = (initialCapacity >= 8) ? initialCapacity : 8;
    size = 0;
    arr = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
    std::cout << "Copy c-tor" << std::endl;
    copyOther(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    std::cout << "Operator=" << std::endl;

    if(this != &other){
        destroy();
        copyOther(other);
    }

    return *this;
}

DynamicArray::~DynamicArray()
{
    destroy();
}

void DynamicArray::insert(int value)
{
    if(size == capacity) resizeUp();

    arr[size] = value; /// the same as: arr[size++] = value;
    size++;
}

void DynamicArray::deleteAt(int index)
{
    if(index < 0 || index > size - 1) return;

    for(int i = index; i < size - 1; ++i){
        arr[i] = arr[i + 1];
    }
    size--;
}

int DynamicArray::getSize() const
{
    return size;
}

int DynamicArray::getCapacity() const
{
    return capacity;
}


int DynamicArray::operator[](int index) const
{
    /// what about validation?
    return arr[index];
}

void DynamicArray::print() const
{
    std::cout << "Size: " << size << ", capacity: " << capacity << std::endl;
    for(int i = 0; i < size; ++i){
        std::cout << i + 1 << ". " << arr[i] << std::endl;
    }
}


void DynamicArray::copyOther(const DynamicArray& other)
{
    capacity = other.capacity;
    size = other.size;

    arr = new int[capacity];

    for(int i = 0; i < size; ++i){
        arr[i] = other.arr[i];
    }
}

void DynamicArray::destroy()
{
    delete [] arr;
}

void DynamicArray::resizeUp()
{
    capacity *= 2;
    int* temp = new int[capacity];

    for(int i = 0; i < size; ++i){
        temp[i] = arr[i];
    }

    delete [] arr;
    arr = temp;
}

