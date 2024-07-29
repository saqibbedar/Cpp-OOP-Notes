#include <iostream>
using namespace std;

int main()
{
    // Question 1
    int *a = new int(23);
    delete a;
    delete a;
    cout<< &a<<endl; // random address 0x2004

    // comments from i to vi and its output, are deleted or not. If there are any errors discuss them.
    // int i, *ptr = &i, *ptr2 = nullptr, int array[10];
    // double *pd = new double(33), *pd2 = pd;
    
    int i = 10, *ptr = &i;
    cout<<i<<" "<<*ptr;
    return 0;
}