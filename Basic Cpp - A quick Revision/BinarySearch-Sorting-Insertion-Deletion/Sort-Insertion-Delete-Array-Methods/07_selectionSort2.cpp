#include <iostream>
using namespace std;


void selectionSort(int arr[], int size){
    int i, j;
    for(i = 0; i < size - 1; i++){
        int min = i;
        for(j = i + 1; j < size; j++){
            if(min > arr[j])
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int a[5] = {1, 5, 3, 2, 4};
    selectionSort(a, 5);
    cout<<"Sorted Array is : ";
    for(int i = 0; i< 5; i++){
        cout<<a[i]<<"\t";
    }
    return 0;
}