#include <iostream>
using namespace std;

int& hello(){

}

int main()
{
    int x = 10;
    int &y = x; // here y is the another name of x, an alias of x, means if make change to y then it will reflect to the x because y is the reference of x, both are existing to the same address.

    cout<<"x = "<<x<<", y = "<<y<<endl; // x = 10, y = 10
    y = 45;
    cout<<"x = "<<x<<", y = "<<y<<endl; // x = 45, y = 45
    x = 100;
    cout<<"x = "<<x<<", y = "<<y<<endl; // x = 100, y = 100

    cout<<"address of x is: "<<&x<<", address of y is: "<<&y<<endl; // some random address but same for both.

    return 0;
}