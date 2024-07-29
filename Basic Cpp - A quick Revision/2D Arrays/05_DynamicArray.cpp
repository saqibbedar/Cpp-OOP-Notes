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