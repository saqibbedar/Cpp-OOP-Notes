#include <iostream>
using namespace std;

int* createArray(int size){
    int *arr = new int[size];
    int *temp = arr;
    for(int i= 0; i<size; i++){
        cin>>*temp;
        temp++;
    }
    return arr;
}

int** createArray(int rows, int cols){
    int **arr = new int*[rows];
    int **temp = arr;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>**temp;
            temp++;
        }
    }
    return arr;
}

void display(int* arr, int size){
    int* temp = arr;
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
    
    int *arr = createArray(size);

    display(arr, size);

    delete[] arr;
    return 0;
}

/*
Description: In the context of an array, incrementing a pointer moves it to the next element in the array.

Let's consider an array arr of integers, which are typically 4 bytes each. If arr is pointing to the address 2000, arr+1 would point to the address 2004, not 2001. This is because arr+1 points to the next integer, which is 4 bytes away, not the next byte.

In above code, temp is a pointer that initially points to the same address as arr. When we do temp++, we're moving the temp pointer to the next element in the array. So if temp was pointing to arr[0], after temp++, it would point to arr[1].

This is how we're able to input or output all elements of the array using a loop. Each iteration of the loop increments temp, moving it to the next element, until it has gone through the entire array.

*/