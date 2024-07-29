#include <iostream>
#include <string>
using namespace std;

int* createArray(int size){
    int* arr = new int[size];
    return arr;
}

void read(int *arr, int size){
    int *temp = arr;
    for(int i=0; i<size; i++){
        cin>>*temp;
        temp++;
    }
}

void display(int* arr, int size){
    int *temp = arr;
    for(int i=0; i<size; i++){
        cout<<*temp<<" ";
        temp++;
    }
}

string setWidth(int width){
    string storeSpaces = "";
    while(width > 0){
        storeSpaces += "*";
        width--;
    }
    return storeSpaces;
}

int main()
{
    int size;
    cout<<"Enter array size: ";
    cin>>size;
    cout<<setWidth(10)<<" Enter array Elements "<<setWidth(10)<<endl;
    int *arr = createArray(size);
    read(arr, size);

    display(arr, size);

    delete[] arr;
    return 0;
}
