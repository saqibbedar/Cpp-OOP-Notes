// unsigned: its a data type which don't allow any negative value to be assigned to the variable, by default in c++, variables are signed in nature

#include <iostream>
using namespace std;

int main()
{
    unsigned int a = -10; // assigning -ve value, so it will give some random number not -10 because it supports +ve to infinity numbers
    cout<<a<<endl; // some radom number i.e. 4294967286

    a = 10;
    cout<<a<<endl; // print 10 because we make it +ve

    return 0;
}