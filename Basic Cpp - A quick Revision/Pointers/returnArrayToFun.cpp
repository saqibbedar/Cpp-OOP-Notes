#include <iostream>
using namespace std;

int* createArray(int size){
    int *arr = new int[size];
    int *temp = arr;
    for(int i= 0; i<size; i++){
        cin>>*temp;
        temp++;
    }
    return arr;
}

void revArray(int* arr, int size){
    for(int i = 0; i < size/2; i++){
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

void output(int size){
    int* arr = createArray(size);
    revArray(arr, size);
    for(int i=0; i<size; i++){
        cout<<*(arr+i)<<" ";
    }
    delete[] arr;
}

int main()
{
    int size;
    cout<<"Enter array size: ";
    cin>>size;

    output(size);

    return 0;
}

// Reverse array
// void revArray(int* arr, int size){
//     int *first = arr;
//     int *last = arr+size-1;
//     while (first < last)
//     {
//         int temp = *first;
//         *first = *last;
//         *last = temp;
//         first++;
//         last--;
//     }
// }