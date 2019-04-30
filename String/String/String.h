#ifndef STRING_INCLUDED
#define STRING_INCLUDED

#include <iostream>
using namespace std;

class String
{
    public:
        String();
        String(const char* str);
        String(const String& other);
        String& operator=(const String& other);
        ~String();

        String operator+(const String& other);
        String drop(int n);
        char findBiggest() const;
        bool isAscending() const;


        friend istream& operator>>(istream& in, String& str);
        friend ostream& operator<<(ostream& out, const String& str);

    private:
        char* str;
};

#endif // STRING_INCLUDED
