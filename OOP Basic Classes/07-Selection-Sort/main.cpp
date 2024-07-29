#include "sort.hpp"

int main(){
    int size = 5;
    int *arr = new int[size];
    sort a;
    read(arr, size);
    a.sort_arr(arr, size);
    display(arr, size);
    
    delete[] arr;
    return 0;
}