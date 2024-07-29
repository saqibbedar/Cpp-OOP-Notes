#pragma once
#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;
    int handleDay(int);
    int handleMonth(int);
    int handleYear(int);
    
public:
    // constructors
    Date();
    Date(int);
    Date(int, int);
    Date(int, int, int);
    Date(const Date &);
    ~Date(); // Destructor

    // getters and setters
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setFullDate(int, int, int);

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getFullDate() const;

    // Input output functions
    void print();
    void read();

    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);
};