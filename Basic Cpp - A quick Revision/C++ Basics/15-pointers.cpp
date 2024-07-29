#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    cout<<arr<<endl; // print random address
    int *arrPtr = arr+2; // storing address of 3 index so output is 5
    cout<<arrPtr[0]<<endl; // 5
    cout<<arrPtr[2]<<endl; // 9
    cout<<arrPtr[5]<<endl; // garbage value because last index for pointer was 2 starting from index 3 of array, it holds the address of 3 index and then moves on

    cout<<arrPtr[-1]<<endl; // moving back, output is 3
    cout<<arrPtr[-2]<<endl; // 1
    cout<<arrPtr<<endl; // some address
    cout<<&arrPtr<<endl; // pointer variables address

    return 0;
}