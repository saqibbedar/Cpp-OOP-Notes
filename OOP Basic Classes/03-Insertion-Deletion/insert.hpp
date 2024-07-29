// array insertion

#pragma once
#include <iostream>
using namespace std;

class _insert{
    public:
    void insertElement(int*, int, int, int);
};

void _insert::insertElement(int *arr, int size, int index, int value){
    for(int i=size; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = value;
}   