#include <iostream>
#include <string>
using namespace std;

/*
********** Matrix is **********

            1 2 3
            4 5 6
            7 8 9

***** Diagonal Traverse is (top to bottom) *****

1
2 4
3 5 7
6 8
9

*/

int** createArray(int rows, int cols){

    int** arr = new int *[rows];
    for(int i = 0; i < rows; i++){
        arr[i] = new int[cols];
    }

    return arr;
}

void dealloc(int **arr, int rows){
    for(int i=0; i<rows; i++){
        delete[] arr;
    }
}

void readArray(int **arr, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<"Enter element at index ["<<i<<"]"<<"["<<j<<"]"<<" ";
            cin>>*(*(arr+i)+j);
        }
    }
}

void diagonalTraverseTTB(int **arr, int rows, int cols){
    for(int i=0; i<rows+cols-1; i++){
        for(int j=0; j<rows; j++){
            for(int k=0; k<cols; k++){
                if(j+k == i){
                    // for top to bottom [j][k]
                    cout<<arr[j][k]<<" ";
                }
            }
        }
        cout<<endl;
    }
}

void display(int **arr, int rows, int cols){

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<*(*(arr+i)+j)<<" ";
        }
        cout<<endl;
    }

}

string setWidth(int n){
    string store = "";
    while (n > 0)
    {
        store += "*";
        n--;
    }
    return store;
}

int main(){
    int rows, cols;
    cout<<"Enter rows and cols size..."<<endl;
    cin>>rows>>cols;

    int** matrix = createArray(rows, cols);
    cout<<"\n";
    readArray(matrix, rows, cols);
    cout<<"\n"<<setWidth(10)<<" Matrix is "<<setWidth(10)<<"\n"<<endl;
    display(matrix, rows, cols);

    cout<<"\n"<<setWidth(5)<<" Diagonal Traverse is "<<setWidth(5)<<"\n"<<endl;

    // diagonal traverse from top to bottom
    diagonalTraverseTTB(matrix, rows, cols);

    dealloc(matrix, rows);
    delete[] matrix;

    return 0;
}