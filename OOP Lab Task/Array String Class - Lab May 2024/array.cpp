#include <iostream>
using namespace std;

class Arr
{
    const int size = 10;
    int *arr;

public:
    Arr()
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    void input(int *arr, int size)
    {
        if (size <= this->size)
        {
            cout << "Enter array elements " << endl;
            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }
        }
    }

    int getIndex(int index, int size, int value)
    {
        if (index < size)
        {
            arr[index] = value;
            cout << arr[index];
        }
        else
        {
            cout << "Unable to access the size of array";
        }
    }

    void show(int *arr, int size)
    {
        cout << "Array elements are: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
        }
    }
    ~Arr(){
        delete[] arr;
    }
};

int main()
{
    int *arr = new int[10];
    Arr a;
    a.input(arr, 10);
    a.getIndex(3, 10, 20);
    a.show(arr, 10);

    delete[] arr;

    return 0;
}