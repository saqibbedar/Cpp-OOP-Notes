#include "Rational.hpp"

// main simplification function (find gcd)
void Rational::simplify(){

    if(denom < 0){
        denom = -denom;
        num = -num;
    };

    // find GCD (greatest common multiple) : Euclidean algorithm (n,d,r)
    int n = (num < 0)? -num: num;
    int d = denom;
    int r = n%d;

    while(r!=0){
        n = d;
        d = r;
        r = n%d;
    }

    // d has gcd now, lets divide it with num and denom to get simplest fraction form

    num /= d;
    denom /= d;

}

// constructors & destructor
Rational::Rational(){
    num = 0;
    denom = 0;
}
Rational::Rational(int num, int denom){
    this->num = num;
    this->denom = denom;
}
Rational::Rational(const Rational &r){
    this->num = r.num;
    this->denom = r.denom;
    simplify();
}
Rational::~Rational(){}

// setters
void Rational::setNum(int num){
    this->num = num;
}
void Rational::setDenom(int denom){
    this->denom = denom;
}
void Rational::setBoth(int num, int denom){
    this->num = num;
    this->denom = denom;
}

// getters
int Rational::getNum()const{
    return num;
}
int Rational::getDenom()const{
    return denom;
}

// Arithmetic operations
Rational Rational::operator+(const Rational& r)const{
    int n, d;
    n = (num * r.denom) + (denom * r.num);
    d = (denom * r.denom);
    return Rational(n, d);
}
Rational Rational::operator-(const Rational& r)const{
    int n,d;
    n = (num* r.denom) - (denom * r.num);
    d = denom * r.denom;
    return Rational(n,d);
}
Rational Rational::operator*(const Rational& r)const{
    int n, d;
    n = (num* r.num);
    d = (denom * r.denom);
    return Rational(n, d);
}
Rational Rational::operator/(const Rational& r)const{
    int n, d;
    n = (num / r.denom);
    d = (denom / r.num);
    return Rational(n,d); // The statement return Rational(n, d); is not returning two values at the same time. Instead, it's creating a new object of type Rational using the constructor that takes two arguments (numerator and denominator), and then returning that object.
}

Rational Rational::operator+=(const Rational& r)
{
    num = num * r.denom + r.num * denom;
    denom = denom * r.denom;
    simplify();
    return *this;
}
Rational Rational::operator-=(const Rational& r)
{
    num = num * r.denom - r.num * denom;
    denom = denom * r.denom;
    simplify();
    return *this;
}
Rational Rational::operator*=(const Rational& r)
{
    num = num * r.num;
    denom = denom * r.denom;
    simplify();
    return *this;
}
Rational Rational::operator/=(const Rational& r)
{
    num = num * r.denom;
    denom = denom * r.num;
    simplify();
    return *this;
}

// increment & decrement operations
Rational& Rational::operator++(){
    num = num + denom;
    return *this;
}
Rational& Rational::operator++(int){
    Rational temp = *this;
    num = num + denom;
    return temp;
}
Rational& Rational::operator--(){
    num = num - denom;
    return *this;
}
Rational& Rational::operator--(int){
    Rational temp = *this;
    num = num + denom;
    return *this;
}

// comparison
bool Rational::operator<(const Rational &r)const{
    return(num * r.denom < denom * r.num);
}
bool Rational::operator>(const Rational &r)const{
    return (num * r.denom > denom * num);
}
bool Rational::operator<=(const Rational &r)const{
    return (num * r.denom <= r.denom * num);
}
bool Rational::operator>=(const Rational &r)const{
    return (num * r.denom >= denom * r.num);
}
bool Rational::operator==(const Rational &r)const{
    return (num * r.denom == denom * r.num);
}
bool Rational::operator!=(const Rational &r)const{
    return (num * r.denom != denom * r.num);
}

void display(const Rational &r){
    cout<<r.num<<"    "<<r.denom;
}