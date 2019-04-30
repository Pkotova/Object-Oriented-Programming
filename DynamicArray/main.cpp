#include <iostream>
#include "DynamicArray.h"
using namespace std;

int findMin(const DynamicArray& d)
{
    int min = d[0];
    for(int i = 0; i < d.getSize(); ++i){
        min = (min > d[i]) ? min = d[i] : min;
    }

    return min;
}

DynamicArray removeEven(DynamicArray& d)  /// cannot return DynamicArray& !!!
{
    DynamicArray result;
    for(int i = 0; i < d.getSize(); ++i){
        if(d[i] % 2 != 1) result.insert(d[i]);
    }

    return result;
}

int main()
{
    DynamicArray d;

    cout << "Size: " << d.getSize()
         << ", capacity: " << d.getCapacity() << endl;

    for(int i = 0; i < 9; ++i){
        d.insert(i*3);
        cout << "Size: " << d.getSize()
             << ", capacity: " << d.getCapacity() << endl;
    }

    DynamicArray p(d);

    cout << "\nPrint p: " << endl;
    p.print();


    d.insert(15);
    d.deleteAt(0);
    cout << "\nPrint d: " << endl;
    d.print();

    cout << "\nMinimum: " << findMin(d) << endl;

    cout << "\nRemove odd:" << endl;
    DynamicArray res(18);
    res = removeEven(d);
    res.print();


    return 0;
}
