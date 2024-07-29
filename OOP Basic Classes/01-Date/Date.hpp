#pragma once

#include <iostream>
#include <ostream>
using namespace std;

class Date{
    int day, month, year;
    public:
    Date(int, int, int);
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
    bool operator<(const Date&)const;
};

Date::Date(int d=1, int m = 1, int y = 2023){
    day = d, month = m, year = y;
}
ostream& operator<<(ostream &print, const Date &d){
    print<<d.day<<"/"<<d.month<<"/"<<d.year;
    return print;
}
istream& operator>>(istream &input, Date &d){
    input>>d.day;
    input>>d.month;
    input>>d.year;
    return input;
}
bool Date::operator<(const Date &d)const{
    return (day < d.day && month < d.month && year < d.year);
}