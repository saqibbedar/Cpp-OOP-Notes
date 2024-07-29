#include <iostream>
using namespace std;

void findDiagonal(int arr[3][4], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j=0; j<cols; j++){
            if(i != j){
                arr[i][j] = 0;
            }
        }
    }
}

void readData(int arr[3][4], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j=0; j<cols; j++){
           cin>>arr[i][j];
        }
    }
}

void display(int arr[3][4], int rows, int cols){
    if(rows == cols){
        for(int i = 0; i < rows; i++){
            for(int j=0; j<cols; j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }
    }else{
        for(int i = 0; i < rows; i++){
            for(int j=0; j<rows; j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    
}

int main()
{
    int arr[3][4];
    readData(arr, 3, 4);
    findDiagonal(arr, 3, 4);
    display(arr, 3, 4);

    return 0;
}