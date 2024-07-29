#include <iostream>
using namespace std;

const int ROWS = 4;
const int COLS = 4;

void diagonal(int arr[ROWS][COLS], int rows, int cols){
    for(int i = 0; i < rows; i++){
        cout<<arr[i][i]<<endl;
    }
}

void hello(int (*arr)[], int rows, int cols){
    for(int i=0; i < rows; i++){
        for(int j=0; j<cols; j++){
            cout<<(*arr+i)[i]<<"\t";
        }
        cout<<endl;    
    }
}

int main(){
    int arr[ROWS][COLS] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout<<"The diagonal elements are: "<<endl;
    diagonal(arr, ROWS, COLS);

    return 0;
}
