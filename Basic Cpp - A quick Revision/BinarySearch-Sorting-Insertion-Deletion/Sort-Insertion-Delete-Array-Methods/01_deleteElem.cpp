#include <iostream>
using namespace std;

// teach students pass by value and pass by reference with this example as we have passed size by reference to make changes in main function for size bcz after deletion size must be reduced in order to avoid the printing of garbage values.

void deleteElement(int arr[], int &size, int index){
    for(int i= index; i< size; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

void deleteElem(int *arr, int &size, int index){
    for(int i=index; i<size; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5; 
    cout<<size<<endl; // current size
    deleteElement(arr, size, 2);
    cout<<size<<endl; // size after pass by reference
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}