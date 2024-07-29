#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};

    for (int x : arr)
    {
        if (x == 1)
            cout << "Yes x has " << x << " and ";
        else
            cout << x << " ";
    }
    
    return 0;
}