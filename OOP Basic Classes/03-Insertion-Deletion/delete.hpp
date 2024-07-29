// deletion

#pragma once
#include <iostream>
using namespace std;

class _delete{
    public:
    void del_elm(int*, int&, int);
};
void _delete::del_elm(int *arr, int& size, int index){
    for(int i=index; i<size; i++){
        arr[i] = arr[i+1];
    }
    size--;
}