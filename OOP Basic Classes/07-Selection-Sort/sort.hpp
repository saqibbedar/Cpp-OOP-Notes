#pragma once
#include <iostream>
using namespace std;

class sort
{
    friend void read(int *, int);
    friend void display(int *arr, int size);

public:
    void sort_arr(int *, int);
};

void sort::sort_arr(int *arr, int size)
{
    cout << "***Enter the order you want to sort the array***" << endl;
    cout << "Enter 1 for ascending and 0 descending order: " << endl;
    int x;
    cin >> x;
    if (x)
    {
        // Ascending order
        for (int i = 0; i < size - 1; i++)
        {
            int min = arr[i];
            for (int j = i+1; j < size; j++)
            {
                if (min > arr[j])
                {
                    min = arr[j];
                    arr[j] = arr[i];
                    arr[i] = min;
                }
            }
        }
    }
    else
    {
        // descending order
        for (int i = 0; i < size - 1; i++)
        {
            int max = arr[i];
            for (int j = i+1; j < size; j++)
            {
                if (max < arr[j])
                {
                    max = arr[j];
                    arr[j] = arr[i];
                    arr[i] = max;
                }
            }
        }
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
    cout << "Sorted array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}