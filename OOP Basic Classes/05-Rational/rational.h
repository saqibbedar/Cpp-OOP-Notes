#pragma once
#include<iostream>
using namespace std;
class rational {
private:
    int num, denom; // rational number's numerator and denominator
    void reduce(); // reduce to lowest terms
    //friend void print(rational &); // print function for rational

public:
    void setnum(int n); // set numerator
    void setdenom(int d); // set denominator
    void setboth(int n, int d); // set both numerator and denominator
    int getnum()const; // get numerator
    int getdenom()const; // get denominator
    rational(); // default constructor
    rational(int num, int denom); // parameterized constructor
    // rational(int n); // parameterized constructor with one parameter
    rational(const rational&); // copy constructor
    ~rational(); // destructor

    // arithmetic operations
    const rational& operator+(const rational&)const; // addition
    const rational & operator-(const rational&)const; // subtraction
    const rational &operator*(const rational&)const; // multiplication
    const rational &operator/(const rational&)const; // division

    // increment/decrement operations
    rational& operator++(); // prefix increment
    rational & operator++(int); // postfix increment
    rational& operator--(); // prefix decrement
    rational & operator--(int); // postfix decrement

    // comparison operations
    bool operator<(const rational&)const; // less than
    bool operator>(const rational&)const; // greater than
    bool operator>=(const rational&)const; // greater than or equal to
    bool   operator<=(const rational&)const; // less than or equal to
    bool operator==(const rational&)const; // equal to
    bool operator!=(const rational&)const; // not equal to

   // operator int();
    operator double();


    
    friend istream& operator>>(istream&, rational&);

    friend ostream& operator<<(ostream&, const rational&);
   const rational& operator=(const rational& r);
    
    rational operator+=(const rational& r);
    rational operator-=(const rational& r);

    rational operator*=(const rational& r);
    rational operator/=(const rational& r);
    

};

