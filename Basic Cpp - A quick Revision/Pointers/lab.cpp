#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int; // single way initialization
    int *ptr2;          // double way initialization
    ptr = new int;

    // int size;
    // int *arr = size; // you cannot initialize like this...

    int x= 10, y =20;
    const int* ptr;
    ptr = &x;
    cout<<*ptr<<endl;
    // *ptr = 100; // we can not do this
    ptr = &y;

    int *const ptr = &x;
    cout<<*ptr<<endl;
    *ptr = 50; 
    ptr = &y; // can't do this

    const int* const ptr = &x; 

    short x = 45;


    int *c;
    int dd = 15;
    *c = 2;
    *c = x **c;
    
    return 0;
}