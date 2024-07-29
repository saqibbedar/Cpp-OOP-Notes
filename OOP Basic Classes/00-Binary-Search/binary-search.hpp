#pragma once
#include <iostream>
using namespace std;

class BinarySearch
{
    friend void read(int *, int);
    friend void display(int *arr, int size);

public:
    void binary_search(int *, int, int)const;
};

void BinarySearch::binary_search(int *arr, int size, int target)const{
    int l = 0;
    int h = size -1;
    bool flag = false;

    while(l <= h){
        int mid = (l+h)/2;
        if(arr[mid] == target){
            cout<<arr[mid]<<" found at index ["<<mid<<"]"<<endl;
            flag = true;
            h = mid -1;
        }
        else if(target < arr[mid]){
            h = mid -1;
        }
        else{
            l = mid +1;
        }
    }
    if(!flag){
        cout<<"not found";
    }
}

void read(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index [" << i << "] : ";
        cin >> arr[i];
    }
}

void display(int *arr, int size)
{
    cout << "Founded element is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}