#include <iostream>
using namespace std;

/*
int r = n % 10; 
        arr[N-1-i] = r+'0';
        n/=10;
*/

void integerToString(int n, char arr[], int size){

    int i = 0; // increment
    int result; // store the result

    while (n!=0)
    { 
        result = n % 10;
        arr[size-1-i] = result + '0'; // 
        i++;
        n/=10;
    }

    arr[i] = '\0';

}

int main()
{
    char arr[3];
    integerToString(321, arr, 3);
    cout<<arr;

    return 0;
}