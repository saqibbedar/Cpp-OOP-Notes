#include <iostream>
using namespace std;

const int SIZE = 5;

void sort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        int min = arr[i];
        for(int j=i+1; j<size; j++){
            if(min > arr[j]){
                min = arr[j];
                arr[j] = arr[i];
                arr[i] = min;
            }
        }
    }
}

int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    sort(arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<"\t";
    }

    return 0;
}