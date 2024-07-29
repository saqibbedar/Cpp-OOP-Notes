#include "delete.hpp"
#include "insert.hpp"
#include "show.hpp"

int main()
{
    int size = 20;
    int *arr = new int[size];

    do
    {
        cout << "Enter array size between 0 and "<< size <<" : ";
        cin >> size;
    } while (size < 0 || size > 20);

    read(arr, size);

    int index;

    // insertion
    cout<<"Enter value you want insert into array: ";
    int value; cin>>value;
    do{
        cout<<"Enter index between 0 and "<<size<<" for insertion : ";
        cin>>index;
    }while(index < 0 || index > size-1);

    _insert i;
    i.insertElement(arr, size, index, value);
    display(arr, size);


    // deletion
    do
    {
        cout << "Enter index between 0 and " << size << " for deletion : ";
        cin >> index;
    } while (index < 0 || index > size-1);

    _delete d; // obj to remove elements from array
    d.del_elm(arr, size, index);

    display(arr, size);

    delete[] arr;
    return 0;
}