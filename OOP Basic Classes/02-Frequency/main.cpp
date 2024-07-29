#include "Frequency.hpp"

int main(){
    int size = 5;
    int *arr = new int[size];

    read(arr, size);

    cout<<"Enter a number to search in array: ";
    int target; cin>>target;

    CheckFrequency search;
    int *arr2 = search.check(arr, size, target);

    display(arr, size);

    delete[] arr;
    delete[] arr2;
    return 0;
}