#include "String.h"
#include <cstring>

String::String()
{
    this->str = NULL;
}

String::String(const char* str)
{
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
}

String::String(const String& other)
{
    this->str = new char[strlen(other.str) + 1];
    strcpy(this->str, other.str);
}

String& String::operator=(const String& other)
{
    if(this != &other){
        delete [] this->str;

        this->str = new char[strlen(other.str) + 1];
        strcpy(this->str, other.str);
    }

    return *this;
}

String::~String()
{
    delete [] this->str;
}

String String::operator+(const String& other)
{
    char temp[strlen(str) + strlen(other.str) + 1];

    strcat(temp, str);
    strcat(temp, other.str);

    return String(temp);

}

String String::drop(int n)
{
    String temp(*this);

    temp.str[strlen(temp.str) - n] = '\0';

    return temp;
}

char String::findBiggest() const
{
    int biggest = 0;
    int n = strlen(str);

    for(int i = 1; i < n; ++i){
        if(str[biggest] < str[i]) biggest = i;
    }

    return str[biggest];
}

bool String::isAscending() const
{
    int n = strlen(str);

    for(int i = 1; i < n; ++i){
        if(str[i - 1] > str[i]){
            return false;
        }
    }

    return true;
}

istream& operator>>(istream& in, String& obj)
{
    char temp[100];

    in >> temp;

    delete [] obj.str;

    obj.str = new char[strlen(temp) + 1];
    strcpy(obj.str, temp);

    return in;
}

ostream& operator<<(ostream& out, const String& obj)
{
    out << obj.str;

    return out;
}
