#include<iostream>
#include<cstring>
using namespace std;

const int MAX_N = 100;
enum Classification {DWARF,NORMAL,GIANT};
struct Planet
{
    char* name;
    int distanceFromSun;
    double diameter;
    double mass;
    Classification type;
    void print ()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Distance:"<<distanceFromSun<<endl;
        cout<<"Diameter:"<<diameter<<endl;
        cout<<"Mass:"<<mass<<endl;
        cout<<"Type:";
        switch(type)
        {
        case DWARF:
            cout<<"DWARF";
            break;
        case NORMAL:
            cout<<"NORMAL";
            break;
        default:
            cout<<"GIANT";
            break;
        }
        cout<<endl;
    }
};

bool distanceAndDiameterSwap(const Planet& p1, const Planet& p2)
{
    return ((p1.distanceFromSun<p2.distanceFromSun) || (p1.distanceFromSun==p2.distanceFromSun&& p1.diameter<p2.diameter));
}
void sortPlanets(Planet** planets,const int& length, bool (*toSwap)(const Planet&,const Planet&))
{
    for(int i=0; i<length-1; i++)
    {
        int minEl = i;
        for(int j=i; j<length; j++)
        {
            if (toSwap(*planets[minEl],*planets[j]))
            {
                minEl = j;
            }
        }
        Planet* toSwap = planets[i];
        planets[i] = planets[minEl];
        planets[minEl] = toSwap;
    }
}
int main()
{
    Planet *a = new Planet();
    a->name = "Earth";
    a->distanceFromSun = 23;
    a->diameter = 10;
    a->mass = 3.5;
    a->type = (Classification)0;
    Planet *b = new Planet();
    b->name = "Earth2";
    b->distanceFromSun = 25;
    b->diameter = 5;
    b->mass = 3.5;
    b->type = NORMAL;
    Planet *c = new Planet();
    c->name = "Mars";
    c->distanceFromSun = 12;
    c->diameter = 4.4;
    c->mass = 5.5;
    b->type = GIANT;
    Planet** s = new Planet*[2];
    s[0] = a;
    s[1] = b;
    s[2] = c;
    sortPlanets(s,3,distanceAndDiameterSwap);
    for(int i=0; i<3; i++)
    {
        s[i]->print();
        cout<<endl;
    }
    for(int i=0; i<3; i++)
    {
        delete[] s[i];
    } /// А защо не изтрихме a,b,c???
    delete s;
}
