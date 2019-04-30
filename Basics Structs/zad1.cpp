#include <iostream>
#include <cstring>
using namespace std;

struct Destination
{
    char city[32];
    int kilometers;
};

int main()
{
    /// а)
    Destination d1 = {"Varna", 443},
                d2 = {"Lovech", 152};

    /// б)
    cout << d1.city << " distance to Sofia: " << d1.kilometers << endl;
    cout << d2.city << " distance to Sofia: " << d2.kilometers << endl;

    /// в)
    Destination cities[30];

    /// г)
    for(int i = 0; i < 30; ++i){
        strcpy(cities[i].city, "");
        cities[i].kilometers = 0;
    }

    return 0;
}
