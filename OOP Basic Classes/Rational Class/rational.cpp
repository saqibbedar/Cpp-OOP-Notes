
#include "rational.h"


void rational::setnum(int n)
{
    num = n;
}

void rational::setdenom(int d)
{
    denom = d;
}

void rational::setboth(int n, int d)

{


    num = n;
    denom = d;
    reduce();
}

int rational::getnum() const
{
    return num;
}

int rational::getdenom() const
{
    return denom;
}

rational::rational()
{
    num = 1;
    denom = 2;
}

rational::rational(int num, int denom)
{

    this->num = num;
    this->denom = denom;
    reduce();
}

/*rational::rational(int n)
{
    num = n;
    denom = 2;
    reduce();
}*/

rational::rational(const rational& r)
{
    num = r.num;
    denom = r.denom;
}



rational::~rational()
{}
void rational::reduce() {
    // Finding the greatest common divisor 
    int a = num;
    int b = denom;
    int r;

    // Making sure denominator is positive
    if (denom < 0) {
        a = -a;
        b = -b;
    }

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    // Dividing both numerator and denominator by the GCD
    num /= a;
    denom /= a;
}
const rational&  rational ::  operator+(const rational& r)const
{
    int n, d;
    n = (num * r.denom) + (denom * r.num);
    d = (denom * r.denom);
    return rational(n, d);
}
const rational & rational::operator-(const rational& r)const
{
    int n = (num * r.denom) - (denom * r.num);
    int d = denom * r.denom;
    return rational(n, d);
}
const rational & rational:: operator*(const rational& r)const
{
    int n, d;
    n = (num * r.num);
    d = (denom * r.denom);
    return rational(n, d);
}
const rational& rational::operator/(const rational& r)const
{
    int n, d;
    n = (num * r.denom);
    d = (denom * r.num);
    return rational(n, d);
}



rational& rational :: operator++()
{
    num = num + denom;
    return *this;
}
rational & rational :: operator++(int)
{
    rational temp = *this;
    num = num + denom;
    return temp;
}
rational& rational ::  operator--()
{
    num = num - denom;
    return *this;
}
rational & rational ::  operator--(int)
{
    rational temp = *this;
    num = num - denom;
    return temp;

}



bool rational:: operator<(const rational& r)const
{
    return(num * r.denom < denom * r.num);
}

bool  rational::  operator>(const rational& r)const
{
    return(num * r.denom > denom * r.num);
}
bool  rational ::  operator>=(const rational& r)const
{
    return(num * r.denom >= denom * r.num);
}
bool rational::  operator<=(const rational& r)const
{
    return(num * r.denom >= denom * r.num);
}
bool rational ::  operator==(const rational& r)const
{
    return(num * r.denom == denom * r.num);
}
bool  rational::  operator!=(const rational& r)const
{
    return(num * r.denom != denom * r.num);
}
/*rational ::operator int()
{
    double result;
    static_cast<double>(num / denom);
    return result;
}*/
rational :: operator double()
{
    return((double)num / denom);
}

istream& operator>>(istream& in, rational& r)
{
  int n, d;


    in >> n >> d;

    r.num = n;
    r.denom = d;

    return in;
}

ostream& operator<<(ostream& out, const rational& r)
{
    out << r.num << "/" << r.denom;
    return out;
}
const rational& rational:: operator=(const rational& r)
{
    num = r.num;
    denom = r.denom;
    return *this;
}
rational rational::operator+=(const rational& r)
{
    num = num * r.denom + r.num * denom;
    denom = denom * r.denom;
    reduce();
    return *this;
}
rational rational::operator-=(const rational& r)
{
    num = num * r.denom - r.num * denom;
    denom = denom * r.denom;
    reduce();
    return *this;
}



rational rational::operator*=(const rational& r)
{
    num = num * r.num;
    denom = denom * r.denom;
    reduce();
    return *this;
}
rational rational::operator/=(const rational& r)
{
    num = num * r.denom;
    denom = denom * r.num;
    reduce();
    return *this;
}
