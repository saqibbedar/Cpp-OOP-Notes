#include <iostream>
using namespace std;

void read(int *arr, int size){
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
}

// void search(int *arr, int size, int target){
//     for(int i=0; i<size; i++){
//         if(target == arr[i]){
//             cout<<target <<" found at index : "<<i<<endl;
//             break;
//         }
//     }
// }

// passing size by reference to set it as the found founded arrays size

int* MultipleOccurrence(int *arr, int &size, int target){
    int *holdFoundedElements = new int[size];
    int i, j; // using j for maintaining the index of holdFoundedElements array

    for( i=0, j = 0; i<size; i++){
        if(target == arr[i]){
            holdFoundedElements[j] = i; // storing indexes
            j++;
        }
    }
    size = j;
    return holdFoundedElements;
}

void display(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<"\t";
    }
}

int main()
{
    int size;
    cout<<"Enter array size: ";
    cin>>size;

    int *arr = new int[size];

    cout<<"Enter array values"<<endl;
    read(arr, size);

    cout<<"enter target element"<<endl;
    int target;
    cin>>target;

    int *arr2 = MultipleOccurrence(arr, size, target);

    display(arr2, size);

    delete arr2;
    delete arr;
    return 0;
}