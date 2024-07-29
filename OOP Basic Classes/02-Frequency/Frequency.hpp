#pragma once
#include <iostream>
using namespace std;
#define tab '\t'

class CheckFrequency{
    friend void read(int*, int);
    friend void display(int *arr, int size);
    public:
    int* check(int*, int&, int);
};

int* CheckFrequency::check(int *arr, int& size, int target){
    int *temp = new int[size];
    int i, j;
    for(i=0, j=0; i<size; i++){
        if(target == arr[i]){
            temp[j] = arr[i];
            j++;
        }
    }
    size = j;
    return temp;
}

void read(int *arr, int size){
    for(int i=0; i<size; i++){
        cout<<"Enter element at index ["<<i<<"] : ";
        cin>>arr[i];
    }
}

void display(int *arr, int size){
    cout<<"Elements founded are: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<tab;
    }
}