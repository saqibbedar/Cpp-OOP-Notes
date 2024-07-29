#pragma once
#include <iostream>
using namespace std;

class MinMax{
    public:
        int min(int*, int);
        int max(int*, int);
};

int MinMax::min(int *arr, int size){
    int min_num = arr[0];
    for(int i=0; i<size; i++){
        if(min_num > arr[i])
            min_num = arr[i];
    }
    return min_num;
}

int MinMax::max(int *arr, int size){
    int max_num = arr[0];
    for(int i = 0; i<size; i++){
        if(max_num < arr[i])
            max_num = arr[i];
    }
    return max_num;
}