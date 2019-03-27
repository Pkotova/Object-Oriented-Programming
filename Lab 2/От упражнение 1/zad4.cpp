#include <iostream>
using namespace std;

struct Planet
{
    char name[32];
    double distance,
           diameter,
           weight;
};

/// а) - създава подадената планета
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

/// б) - отпечатва подадената планета
void printPlanet(const Planet& planet)
{
    cout << "Name: " << planet.name << ", "
         << "distance to sun: " << planet.distance << ", "
         << "diameter: " << planet.diameter << ", "
         << "weight: " << planet.weight << endl;
}

/// в) - изчислява броя секунди, за които светлината достига до планетата
int getTime(const Planet& planet)
{
    int speedOfLight = 299792;
    return planet.distance / speedOfLight;
}

/// проверява дали първата планета има по-голям диаметер
bool hasBiggerDiameter(const Planet& p1, const Planet& p2)
{
    return p1.diameter > p1.diameter;
}

/// проверява дали първата планета е по-лека
bool hasSmallerWeight(const Planet& p1, const Planet& p2)
{
    return p1.weight < p2.weight;
}

/// проверява дали първата планета е по-близо до слънцето
bool isCloserToSun(const Planet& p1, const Planet& p2)
{
    return p1.distance < p2.distance;
}

/// намира планета, която е минимална/максимална по някое от полетата,
/// определено от компаратора
Planet getPlanet(const Planet* planets, int n,
                 bool (*comparator)(const Planet& p1, const Planet& p2))
{
    Planet p = planets[0];
    for(int i = 1; i < n; ++i){
        if(comparator(planets[i], p)){
            p = planets[i];
        }
    }

    return p;
}


int main()
{
    /// а) - създаване на масив от планети
    const int MAX = 10; /// Брой планети
    int n;

    do{
        cout << "Enter number of planets [1, " << MAX << "]: ";
        cin >> n;
    }while(n < 1 || n > MAX);

    Planet planets[MAX]; /// Масив от планети

    for(int i = 0; i < n; ++i){
        cout << "Planet " << i + 1 << ":"<< endl;
        createPlanet(planets[i]);
    }

    /// б) - отпечатване на масива от планети
    for(int i = 0; i < n; ++i){
        cout << "Planet " << i + 1 << ":" << endl;
        printPlanet(planets[i]);
    }
    cout << endl;

    /// в)
    cout << "Planet with biggest diameter:" << endl;
    Planet biggest = getPlanet(planets, n, hasBiggerDiameter);
    printPlanet(biggest);

    /// г)
    cout << "Planet with least weight:" << endl;
    Planet lightest = getPlanet(planets, n, hasSmallerWeight);
    printPlanet(lightest);

    /// д)
    cout << "Planet closest to sun:" << endl;
    Planet closest = getPlanet(planets, n, isCloserToSun);
    printPlanet(closest);


    return 0;
}
