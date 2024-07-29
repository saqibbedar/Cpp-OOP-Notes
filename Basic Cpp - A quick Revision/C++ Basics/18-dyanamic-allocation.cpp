// 2d arrays: Array of arrays

#include <iostream>
using namespace std;

int main()
{
    int rows = 3;
    int cols = 3;

    int **matrix = new int *[rows]; // intermediate array is created
    // here new will return starting address

    // allocation for each integer
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    // deallocation
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
    return 0;
}