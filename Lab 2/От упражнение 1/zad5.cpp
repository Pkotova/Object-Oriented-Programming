#include <iostream>
using namespace std;

struct Planet
{
    char name[32];
    double distance,
           diameter,
           weight;
};

/// създава подадената планета
void createPlanet(Planet& planet)
{
    cout << "Enter name: ";
    cin >> planet.name;

    /// validate distance to sun
    do{
        cout << "Enter distance to sun: ";
        cin >> planet.distance;
    }while(planet.distance <= 0);

    /// validate diameter
    do{
        cout << "Enter diameter: ";
        cin >> planet.diameter;
    }while(planet.diameter <= 0);

    /// validate weight
    do{
        cout << "Enter weight: ";
        cin >> planet.weight;
    }while(planet.weight <= 0);
}

/// отпечатва подадената планета
void printPlanet(const Planet& planet)
{
    cout << "Name: " << planet.name << ", "
         << "distance to sun: " << planet.distance << ", "
         << "diameter: " << planet.diameter << ", "
         << "weight: " << planet.weight << endl;
}

/// запълва масива от указатели към планети
void createPArray(Planet* const planets, int n, Planet** pPlanets)
{
    for(int i = 0; i < n; ++i){
        pPlanets[i] = &planets[i];
    }
}

/// сортира планетите в низходящ ред по разстояние до слънцето и диаметър
void sortPlanets(Planet** pPlanets, int n)
{
    for(int i = 0; i < n -1; ++i){
        Planet* maxPlanet = pPlanets[i];
        int k = i; /// maxIndex

        for(int j = i + 1; j < n; ++j){
            if(maxPlanet->distance < pPlanets[j]->distance ||
               (maxPlanet->distance == pPlanets[j]->distance
                && maxPlanet->diameter < pPlanets[j]->diameter)){
                    maxPlanet = pPlanets[j];
                    k = j;
               }
        }
        swap(pPlanets[i], pPlanets[k]);
    }
}

int main()
{
    const int MAX = 10; /// максимален брой планети
    int n;

    do{
        cout << "Enter number of planets [1, " << MAX << "]: ";
        cin >> n;
    }while(n < 1 || n > MAX);

    Planet planets[MAX]; /// масив от планети
    Planet* pPlanets[MAX]; /// масив от указатели към планети, който ще сортираме

    for(int i = 0; i < n; ++i){
        cout << "Planet " << i + 1 << ":" << endl;
        createPlanet(planets[i]);
    }
    cout << endl;

    /// а) - запълваме масива от указатели към планетите
    createPArray(planets, n, pPlanets);

    /// б) - сортиране на планетите в низходящ ред по разстояние до слънцето и диаметър
    sortPlanets(pPlanets, n);

    /// в) - отпечатване на сортираните планети
    for(int i = 0; i < n; ++i){
        printPlanet(*pPlanets[i]);
    }

    return 0;
}
