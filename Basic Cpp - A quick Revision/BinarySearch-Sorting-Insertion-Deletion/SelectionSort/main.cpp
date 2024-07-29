#include <iostream>
#include "SelectionSort.h"
using namespace std;

int main()
{
    SortArray sort;

    int arr[5] = {3, 1, 8, 2, 10};

    cout << "Sorting in ascending order" << endl;
    sort.sortAO(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << "\nSorting in descending order" << endl;
    sort.sortDO(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "\t";
    }

    return 0;
}
 
// g++ -o main main.cpp SelectionSort.cpp
// after it run ./executable-file-name in this case ./main