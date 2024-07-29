// double pointer: pointer to pointer, storing pointer address into pointer, we cannot do it with single pointer so we need double pointer.

#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *ptr = &x;
    int **dptr = &ptr;

    cout<<"x = "<<x<<endl; // 10
    cout<<"&x = "<<&x<<endl; // 0x2000
    cout<<"ptr = "<<ptr<<endl; // 0x2000
    cout<<"*ptr = "<<*ptr<<endl; // 10
    cout<<"&ptr = "<<&ptr<<endl; // 0x2004
    cout<<"dptr = "<<dptr<<endl; // 0x2004
    cout<<"*dptr = "<<*dptr<<endl; // 0x2006
    cout<<"**dptr = "<<**dptr<<endl; // 10

    return 0;
}