#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

class Time
{
    public:
        Time();
        Time(int hours, int minutes);

        int getHours() const;
        int getMinutes() const;

        void setHours(int newHours);
        void setMinutes(int newMinutes);

        void print() const;

        Time operator+(const Time& other) const;
        Time operator-(const Time& other) const;
        operator int() const;

    private:
        int hours;
        int minutes;
        void reset(int hours, int minutes);
        void simplify();
};

#endif // TIME_H_INCLUDED
