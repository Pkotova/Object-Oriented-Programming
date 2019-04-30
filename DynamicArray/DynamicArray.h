#ifndef DYNAMIC_ARRAY_H_INCLUDED
#define DYNAMIC_ARRAY_H_INCLUDED

class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(int initialCapacity);
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    ~DynamicArray();

    void insert(int value);
    void deleteAt(int index);

    int getSize() const;
    int getCapacity() const;
    int operator[](int index) const;
    void print() const;

private:
    int capacity;
    int size;
    int* arr;

    void copyOther(const DynamicArray& other);
    void destroy();
    void resizeUp();
};

#endif // DYNAMIC_ARRAY_H_INCLUDED
