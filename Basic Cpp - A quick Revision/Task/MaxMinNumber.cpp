// write a c++ program to find max and min num in an array
// Date: Wednesday, 21st Feb 2024

#include <iostream>

int max(int arr[], int size){
    int max = arr[0];
    for(int i = 0; i< size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int min(int arr[], int size){
    int max = arr[0];
    for(int i = 0; i< size; i++){
        if(max > arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int main(){

    int a[5] = {1, 2, 3, 4, 5};

    std::cout<<"Max number in array is: "<< max(a, 5)<<std::endl;
    std::cout<<"Min number in array is: "<< min(a, 5)<<std::endl;

    return 0;
}