// write a c++ program to find max and min num in an array

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
    int size;
    std::cout<<"Enter size of Array: ";
    std::cin>> size;
    int *arr = new int[size]; // allocate dynamic memory

    std::cout<<"Enter values of Array"<<std::endl;
    for(int i = 0; i < size; i++){
        std::cin>> *(arr+i);
    }

    std::cout<<"Max number in array is: "<< max(arr, 5)<<std::endl;
    std::cout<<"Min number in array is: "<< min(arr, 5)<<std::endl;

    delete[] arr; // deallocate dynamic memory
    return 0;
}