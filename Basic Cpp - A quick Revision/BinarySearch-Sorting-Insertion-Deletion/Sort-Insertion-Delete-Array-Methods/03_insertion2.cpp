#include <iostream>
using namespace std;

const int SIZE = 5;

void insertion(int *arr, int size, int index, int value){
    for(int i = size; i > index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = value;
}

void insert2(int *arr, int size, int index, int value){
    for(int i = size; i>= index; i--){
        arr[i] = arr[i-1];
        (i = index )? arr[index] = value : NULL;
    }
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<"\t";
    }
}

int main()
{
    int arr[SIZE] = {1,3, 4, 5, 7};
    insert2(arr, SIZE, 3, 200);

    for(int i=0; i<SIZE; i++){
        cout<<arr[i]<<"\t";
    }

    // int n = 10;
    // int count = 1;
    // while(count <= n){
    //     cout<<count<<" : Say! Hello"<<endl;
    //     count++;
    // }
    // while(count <= n+10){
    //     cout<<count<<" : "<<n<<endl;
    //     count = count + 1;
    // }
    // cout<<1 <<  " : "<<variable<<endl;
    // cout<<2 <<  " : "<<variable<<endl;
    // cout<<3 <<  " : "<<variable<<endl;
    // cout<<4 <<  " : "<<variable<<endl;
    // cout<<5 <<  " : "<<variable<<endl;
    // cout<<6 <<  " : "<<variable<<endl;
    // cout<<7 <<  " : "<<variable<<endl;
    // cout<<8 <<  " : "<<variable<<endl;
    // cout<<9 <<  " : "<<variable<<endl;
    // cout<<10 << " : "<< variable<<endl;

    // int arr[SIZE] = {1, 43, 9, 10, 100};

    // int index, value;
    // cout<<"User enter index where you want enter the value: ";
    // cin>>index;// 0

    // cout<<"User enter value: ";
    // cin>>value; // 100

    // insertion(arr, 5, index, value);
    // cout<<"Array elements are : ";
    // display(arr, 5);

    return 0;
}