#include <iostream>
using namespace std;

struct Person
{
    int age;
    char name[32];
};

void read(Person* people, Person** pPeople, int n)
{
    for(int i = 0; i < n; ++i){
        cout << "Enter name and age: ";
        cin >> people[i].name >> people[i].age; /// missing validation
        pPeople[i] = &people[i]; /// store the address of i'th Person
    }
}

/// sort array of type Person using selection sort
void sortPeopleBad(Person* people, int n) /// Person* - pointer to array of type Person
{
    for(int i = 0; i < n - 1; ++i){
        int minIndex = i;
        Person minPerson = people[i];

        for(int j = i + 1; j < n; ++j){
            if(people[j].age < minPerson.age){
                minPerson = people[j];
                minIndex = j;
            }
        }

        swap(people[i], people[minIndex]);
    }

}

/// sort the array of pointers using selection sort
void sortPeople(Person** people, int n) /// Person** - pointer to array of pointers to Person
{
    for(int i = 0; i < n - 1; ++i){
        int minIndex = i;
        Person* minPerson = people[i];

        for(int j = i + 1; j < n; ++j){
            if(people[j]->age < minPerson->age){
                minPerson = people[j];
                minIndex = j;
            }
        }

        swap(people[i], people[minIndex]);
    }
}


int main()
{
    const int MAX = 10;

    int n;

    do{
        cout << "Enter number of students (up to 10): ";
        cin >> n;
    }while(n < 0 || n > 10);


    Person arr[n]; /// array of type Person
    Person* pArr[n]; /// array of pointers to Person


    read(arr, pArr, n);
    cout << endl << "Print after reading: " << endl;
    for(int i = 0; i < n; ++i){
        cout << "Name: " << arr[i].name << " , age: " << arr[i].age << endl;
    }

    /**
    cout << endl << "Print after bad sorting: " << endl;
    sortPeople(pArr, n);
    for(int i = 0; i < n; ++i){
        cout << "Name: " << arr[i].name << " , age: " << arr[i].age << endl;
    }*/

    cout << endl << "Print after sorting with pointers: " << endl;
    sortPeople(pArr, n);
    for(int i = 0; i < n; ++i){
        cout << "Name: " << pArr[i]->name << " , age: " << pArr[i]->age << endl;
    }


    cout << endl << "Print the array of type Person: " << endl;
    sortPeople(pArr, n);
    for(int i = 0; i < n; ++i){
        cout << "Name: " << arr[i].name << " , age: " << arr[i].age << endl;
    }
    cout << "The array of type Person remains unchanged!" << endl;


    return 0;
}
