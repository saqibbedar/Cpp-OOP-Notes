#include "binary-search.hpp"

int main(){
    int size = 5;
    int *arr = new int[size];
    read(arr, size);
    BinarySearch search;
    int target;
    cout<<"Enter a number to search in array: ";
    cin>>target;
    search.binary_search(arr, size, target);

    delete[] arr;
    return 0;
}