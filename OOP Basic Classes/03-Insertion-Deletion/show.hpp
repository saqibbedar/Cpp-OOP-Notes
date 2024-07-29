#pragma once
#include <iostream>
using namespace std;

class show{
    friend void read(int*, int);
    friend const void display(int*, int);
};

void read(int *arr, int size){
    for(int i=0; i<size; i++){
        cout<<"Enter element at index ["<<i<<"] : ";
        cin>>arr[i];
    }
}

const void display(int *arr, int size){
    cout<<"Modified Array: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}