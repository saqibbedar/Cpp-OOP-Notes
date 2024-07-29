#include <iostream>
using namespace std;

int main()
{
    int x = 10; 
    int y = 20;
    const int *ptr;
    ptr = &x;
    cout<<*ptr<<endl; // 10

    ptr = &y;
    cout<<*ptr<<endl; // 20

    // it means with help of pointers we can change the nature of constants and play with differently.

    int size;
    cin>>size;
    const int *ptr2 = &size;
    cout<<*ptr2<<endl;

    int z = 100;
    const int *ptr3 = &z;
    cout<<*ptr3<<endl; // 100
    z = 200;
    cout<<*ptr3<<endl; // 200

    return 0;
}