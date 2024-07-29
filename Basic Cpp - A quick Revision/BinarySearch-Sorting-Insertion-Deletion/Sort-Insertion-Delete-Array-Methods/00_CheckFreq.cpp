// Date: Wednesday, 21 Feb 2024

#include <iostream>

const int SIZE = 10;

void readData(int arr[], int s){
    for(int i = 0; i < s; i++){
        std::cout<<"Enter value at "<< i <<" index: ";
        std::cin>>arr[i];
    }
}

void displayData(int arr[], int s){
    std::cout<<"Array Elems: ";
    for(int i = 0; i < s; i++){
        std::cout<<arr[i]<<"\t";
    }
}

void checkFreq(int arr[], int s, int target){

    for(int i = 0; i < s; i++){
        if(target == arr[i]){
            std::cout<<target<<" is at index : "<<i<<std::endl;
        }
    }
}

int main(){
    int arr[SIZE];
    readData(arr, SIZE);
 
    std::cout<<"Enter a number to search in array: ";
    int search;
    std::cin>>search;

    checkFreq(arr, SIZE, search);

    return 0;
}