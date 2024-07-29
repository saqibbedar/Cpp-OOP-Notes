// Insertion and Delete 

#include <iostream>
using namespace std;

const int SIZE = 20;

// insert Element in array
void insertElement(int arr[], int size, int index, int value){
    
    for(int i = size; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = value;
}

// delete element in array
void deleteElement(int arr[], int size, int index){
    for(int i = index; i < size; i++){
        arr[i] = arr[i + 1];
    }
}

// readData in Array
void readData(int arr[], int length){
    for(int i = 0; i < length; i++){
        cout<<"Enter Array Element at index "<<i<<" : ";
        cin>>arr[i];
    }
}

// displayData in array
void displayData(int arr[], int length){
    for(int i = 0; i < length; i++){
        cout<<arr[i]<<"\t";
    }
}

int main(){
    int arr[SIZE];

    int arrSize; // Get size of array form user

    do{
        cout<<"Enter Array SIZE between 0 and 20: ";
        cin>>arrSize; 
    }while(arrSize <= 0 || arrSize > 20);

    readData(arr, arrSize);

    // Insertion
    int index, value; 
    do{
        cout<<"Enter index between 0 and " <<arrSize <<" : ";
        cin>>index;
    }while(index < 0 || index > arrSize);
    cout<<"Enter value : ";
    cin>>value;
    insertElement(arr, arrSize, index, value);
    cout<<"\nArray after insertion: ";
    displayData(arr, arrSize);

    cout<<endl;
    // Deletion
    do{
        cout<<"Enter index between 0 and " <<arrSize <<" : ";
        cin>>index;
    }while(index < 0 || index > arrSize);
    deleteElement(arr, arrSize, index);
    cout<<"\nUpdated Array is: ";
    displayData(arr, arrSize);
    
    return 0;
}
