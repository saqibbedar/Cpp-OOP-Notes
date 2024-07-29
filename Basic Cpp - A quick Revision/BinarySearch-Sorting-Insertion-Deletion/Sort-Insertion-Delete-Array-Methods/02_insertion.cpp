#include <iostream>
using namespace std;

void insertion(int *arr, int size, int index, int value){
    for(int i=size; i>=index; i--){
        arr[i] = arr[i-1];
        (i=index)? arr[index] = value: NULL;
    }
}

int main()
{
    const int SIZE = 10;
    int arr[SIZE] = {10, 20, 30, 40, 50};
    insertion(arr, SIZE, 3, 100);

    for(int i=0; i<SIZE; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}