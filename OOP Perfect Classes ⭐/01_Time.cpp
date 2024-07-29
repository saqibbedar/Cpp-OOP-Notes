/*

Create a class Time having data members for hours, minutes and seconds. Create a constructor with default arguments. Make sure to initialize the data members with valid range e of values for hours (0-23), minutes (0-59) and seconds (0-59) If any parameter is incorrect, initialize the corresponding data member with 0. Overload the post increment operator ++ that increments the time by one, second. The increment operator must increment the Time correctly into next minute and/or next hour. Overload the operator << to print the Time in the format hh:mm:ss i.e. print a leading 0 if hours, minutes or seconds are less than 10. Overload the operator < to check if one time object is less than the other Overload int() operator to convert time into an integer(i.e. total number of seconds)

At last, write main() function to demonstrate the time.

*/

#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
    int hours, minutes, seconds;

public:
    // parametrized constructor with default values
    Time(int h = 0, int m = 0, int s = 0);

    // overload the post increment operator++
    Time operator++(int);

    // overload the Insertion (<<) operator
    friend ostream &operator<<(ostream& out, const Time &);

    // overload < operator
    bool operator<(const Time &) const;

    // overload int() operator
    operator int() const;
};

Time::Time(int h, int m, int s)
{
    (h >= 0 && h <= 23) ? hours = h : hours = 0;
    (m >= 0 && h <= 59) ? minutes = h : minutes = 0;
    (s >= 0 && s <= 59) ? seconds = h : seconds = 0;

    // if (h >= 0 && h <= 23)
    //     hours = h;
    // else
    //     hours = 0;
    // if (m >= 0 && m <= 59)
    //     minutes = m;
    // else
    //     minutes = 0;
    // if (s >= 0 && s <= 59)
    //     seconds = s;
    // else
    //     seconds = 0;
}

Time Time::operator++(int)
{
    Time temp = *this;
    seconds++;
    if (seconds > 59)
    {
        seconds = 0;
        minutes++;
    }
    if (minutes > 59)
    {
        minutes = 0;
        hours++;
    }
    if (hours > 23)
    {
        hours = 0;
    }
    return temp;
}

ostream &operator<<(ostream &out, const Time &t)
{
    out << setw(2) << setfill('0') << t.hours << ":"
        << setw(2) << setfill('0') << t.minutes << ":"
        << setw(2) << setfill('0') << t.seconds;
    return out;
}

bool Time::operator<(const Time &t) const
{
    if (hours < t.hours)
    {
        return true;
    }
    else if (hours > t.hours)
    {
        return false;
    }
    else
    { // hours are equal, compare minutes
        if (minutes < t.minutes)
        {
            return true;
        }
        else if (minutes > t.minutes)
        {
            return false;
        }
        else
        { // minutes are equal, compare seconds
            return seconds < t.seconds;
        }
    }
}

Time::operator int() const
{
    return (hours * 3600 + minutes * 60 + seconds);
}

int main()
{
    Time t1(9, 57, 58);
    Time t2(23, 58, 59);

    cout<<"Time (t1) is: "<<t1<<endl;
    cout<<"Time (t2) is: "<<t2<<endl;

    t2 = t1++;

    cout<<"Time (t1) after post-increment: "<<t1<<endl;
    cout<<"Time (t2) after assigned with t1: "<<t2<<endl;

    if(t1 < t2)
        cout<<"t1 ["<<t1<<"] is less than t2 ["<<t2<<"]"<<endl;
    else
        cout<<"t1 ["<<t1<<"] is greater than t2 ["<<t2<<"]"<<endl;

    int totalSeconds = t1;
    cout<<"Total seconds in t1 are: "<<totalSeconds<<endl;

    return 0;
}
