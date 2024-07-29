// Selection sort
#include <iostream>
using namespace std;

const int SIZE = 5;

// Sorting Array in normal way using selection sort

// Ascending Order
void selectionSortAscendingOrder(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = arr[i];
        for (int j = i + 1; j < size; j++)
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

// descending order
void selectionSortDescendingOrder(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int max = arr[i];
        for (int j = i + 1; j < size; j++)
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

// Sorting Array by Reversing Loop

// Ascending order
void selectionSortAO(int arr[], int size)
{

    for (int i = size - 1; i >= 1; i--)
    {
        int min = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (min < arr[j])
            {
                min = arr[j];
                arr[j] = arr[i];
                arr[i] = min;
            }
        }
    }
}

// Descending order
void selectionSortDO(int arr[], int size)
{

    for (int i = size - 1; i >= 1; i--)
    {
        int max = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (max > arr[j])
            {
                max = arr[j];
                arr[j] = arr[i];
                arr[i] = max;
            }
        }
    }
}

// Display data
void displayData(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}

int main()
{
    int a[SIZE] = {4, 8, 5, 1, 10};

    // Ascending order
    cout << "\nAscending order\n";
    selectionSortAscendingOrder(a, SIZE);
    displayData(a, SIZE);

    // Descending order
    cout << "\nDescending order\n";
    selectionSortDescendingOrder(a, SIZE);
    displayData(a, SIZE);

    // Ascending order
    cout << "\nAscending order\n";
    selectionSortAO(a, SIZE);
    displayData(a, SIZE);

    // Descending order
    cout << "\nDescending order\n";
    selectionSortDO(a, SIZE);
    displayData(a, SIZE);

    return 0;
}