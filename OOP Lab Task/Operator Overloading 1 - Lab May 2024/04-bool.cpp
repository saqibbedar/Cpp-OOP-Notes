#include <iostream>
#include <ostream>
using namespace std;

class Number
{
    int a;

public:
    Number()
    {
        a = 0;
    }
    void display()
    {
        cout << "Value of object is: " << a << endl;
    }
    Number(int x)
    {
        a = x;
    }
    Number operator--()
    {
        --a;
        return Number(a);
    }
    Number operator++()
    {
        ++a;
        return Number(a);
    }
    Number operator+(Number x)
    {
        // int temp = a + x.a; return Number(temp);
        return Number(a + x.a);
    }
    Number operator+=(Number x)
    {
        return Number(a += x.a);
    }
    Number operator*=(Number x)
    {
        a *= x.a;
        return Number(a);
    }
    bool operator==(Number x)
    {

        return a == x.a;
    }
};

int main()
{
    Number a = 10, b = 11;
    (b == a) ? cout << "Equal" : cout << "Not equal";

    return 0;
}