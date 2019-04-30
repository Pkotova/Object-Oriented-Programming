#include <iostream>
#include "Time.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int hours, int minutes)
{
    reset(hours, minutes);
}

int Time::getHours() const
{
    return this->hours;
}

int Time::getMinutes() const
{
    return this->minutes;
}

void Time::setHours(int newHours)
{
    this->hours = newHours;
}

void Time::setMinutes(int newMinutes)
{
    this->minutes = newMinutes;
    simplify();
}

void Time::print() const
{
    std::cout << "Time: " << this->hours << "h " << this->minutes << "min" << std::endl;
}

Time Time::operator+(const Time& other) const
{
    Time sum;

    sum.hours = this->hours + other.hours;
    sum.minutes = this->minutes + other.minutes;
    sum.simplify();

    return sum;
}

Time Time::operator-(const Time& other) const
{
    Time sub;

    int m1, m2;

    m1 = other.hours*60 + other.minutes;
    m2 = hours*60 + minutes;

    sub.hours = (m2 - m1) / 60;
    sub.minutes = (m2 - m1) % 60;

    return sub;
}

Time::operator int() const
{
    return hours*60 + minutes;
}

void Time::reset(int hours, int minutes)
{
    this->hours = hours;
    this->minutes = minutes;
    simplify();
}

void Time::simplify()
{
    if(minutes >= 60){
        hours += minutes / 60;
        minutes = minutes % 60;
    }
}

