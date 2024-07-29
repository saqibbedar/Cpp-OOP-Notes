#include <iostream>
using namespace std;

int* revArray(int *arr, int size){
    for(int i = 0; i<size/2; i++){
        int temp = arr[i]; 
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int* rev(int *arr, int size){
    for(int i=0; i<size/2; i++){
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size -1-i] = temp;
    }
}

int* createArray(int size){
    int *arr = new int[size];
    int *temp = arr;
    for(int i= 0; i<size; i++){
        cin>>*temp;
        temp++;
    }
}

void display(int *arr, int size){
    int *temp = arr;
    for(int i=0; i<size; i++){
        cout<<*temp<<" ";
        temp++;
    }
}

int main()
{
    int size;
    cout<<"Enter array size: ";
    cin>>size;
    int *arr = new int[size];

    int *temp = arr; // Use a temporary pointer to keep track of the start of the array
    
    for(int i=0; i<size; i++){
        cin>>*(temp);
        temp++;
    }

    revArray(arr, size);
    display(arr, size);

    delete[] arr;
    return 0;
}