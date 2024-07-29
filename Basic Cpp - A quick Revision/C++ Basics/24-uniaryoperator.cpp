#include <iostream>
using namespace std;

int a = 10;
// we use :: for accessing global variables

int main()
{
    {
        int a = 100;
        cout << a << endl;
    } // {} are called independent scope or unnamed scope
    cout << ::a;
    return 0;
}