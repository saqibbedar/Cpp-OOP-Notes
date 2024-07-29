#include "SelectionSort.h"

void SortArray::sortAO(int *arr, int size)
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

void SortArray::sortDO(int *arr, int size)
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
