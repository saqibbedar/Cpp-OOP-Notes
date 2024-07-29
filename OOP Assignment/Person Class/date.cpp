#include "date.h"

// Date handlers
int Date::handleDay(int d) {
    while (d > 30 || d <= 0) {
        cout << "Error: Invalid date! Enter a valid day (1-30): ";
        cin >> d;
    }
    return d;
}

int Date::handleMonth(int m) {
    while (m > 12 || m <= 0) {
        cout << "Error: Invalid month! Enter a valid month (1-12): ";
        cin >> m;
    }
    return m;
}

int Date::handleYear(int y) {
    while (y > 2024 || y <= 1950) {
        cout << "Error: Invalid year! Enter a valid year (1951-2024): ";
        cin >> y;
    }
    return y;
}

// Default constructor
Date::Date() : day(0), month(0), year(0)
{
    // cout << "Date Default constructor" << endl;
}
// single parametrized constructor
Date::Date(int d) : day(handleDay(d)), month(0), year(0)
{
    // cout << "Date 1 parametrized constructor" << endl;
}
// Double parametrized constructor
Date::Date(int d, int m) : day(handleDay(d)), month(handleMonth(m)), year(0)
{
    // cout << "Date 2 parametrized constructor" << endl;
}
// Parametrized constructor - for initializing all members
Date::Date(int d, int m, int y) : day(handleDay(d)), month(handleMonth(m)), year(handleYear(y))
{
    // cout << "Date 3 parametrized constructor" << endl;
}
// copy constructor
Date::Date(const Date &other) : day(handleDay(other.day)), month(handleMonth(other.month)), year(handleYear(other.year))
{
    // cout << "Date copy constructor" << endl;
}
// Destructor
Date::~Date()
{
    // cout << "Date Destructor" << endl;
}

// setters
void Date::setDay(int d){
    day = handleDay(d);
}
void Date::setMonth(int m){    
    month = handleMonth(m);
}
void Date::setYear(int y){
    year = handleYear(y);
}
void Date::setFullDate(int d, int m, int y){
    day = handleDay(d);
    month = handleMonth(m);
    year = handleYear(y);
}

// getters
int Date::getDay() const {
    return day;
}
int Date::getMonth() const {
    return month;
}
int Date::getYear() const {
    return year;
}
int Date::getFullDate() const{
    int fullDate = year * 1000 + month * 100 + day; // return date [YYMMDD]
    return fullDate;
}

// Input output functions

void Date::print(){
    cout<<*this;
}
void Date::read(){
    cin>>*this;
}

ostream &operator<<(ostream &out, const Date &other)
{
    out << other.day << "/" << other.month << "/" << other.year;
    return out;
}
istream &operator>>(istream &in, Date &other)
{
    int d, m, y;
    cout << "Enter Day: [1-30]: ";
    in >> d;
    other.day = other.handleDay(d);
    cout << "Enter month: [1-12]: ";
    in >> m;
    other.month = other.handleMonth(m);
    cout << "Enter year: [1951-2024]: ";
    in >> y;
    other.year = other.handleYear(y);

    return in;
}