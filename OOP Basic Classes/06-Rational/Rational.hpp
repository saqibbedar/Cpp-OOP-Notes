#pragma once

#include <iostream>
using namespace std;

class Rational{
    int num, denom; // num = numerator, denom = denominator
    void simplify();
    friend void display(const Rational &r);

    public:

    // constructors & destructor
    Rational();
    Rational(int, int);
    Rational(const Rational &);
    ~Rational();

    // setters
    void setNum(int);
    void setDenom(int);
    void setBoth(int, int);

    // getters
    int getNum()const;
    int getDenom()const;

    // Operator Overloading

    // Arithmetic operations
    Rational operator+(const Rational&)const;
    Rational operator-(const Rational&)const;
    Rational operator*(const Rational&)const;
    Rational operator/(const Rational&)const;

    Rational operator+=(const Rational &r);
    Rational operator-=(const Rational &r);
    Rational operator*=(const Rational &r);
    Rational operator/=(const Rational &r);

    // increment & decrement operations
    Rational& operator++();
    Rational& operator++(int);
    Rational& operator--();
    Rational& operator--(int);

    // comparison
    bool operator<(const Rational &r)const;
    bool operator>(const Rational &r)const;
    bool operator<=(const Rational &r)const;
    bool operator>=(const Rational &r)const;
    bool operator==(const Rational &r)const;
    bool operator!=(const Rational &r)const;
};