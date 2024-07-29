#include <iostream>
using namespace std;

int** create2dArray(int rows, int cols){
    int **arr = new int*[rows];
    for(int i=0; i<rows; i++){
        *(arr+i) = new int[cols];
    }
    return arr;
}

void read(int** arr, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>*(*(arr+i)+j);
        }
    }
}

int** transpose(int** arr, int rows, int cols){
    int** transposed = create2dArray(cols, rows);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            transposed[j][i] = arr[i][j];
        }
    }
    return transposed;
}

void display(int** arr, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dealloc(int** arr, int rows){
    for(int i= 0; i<rows; i++){
        delete[] *(arr+i);
    }
    delete[] arr;
}

int main(){
    int rows, cols;
    cin>>rows>>cols;

    int** arr = create2dArray(rows, cols);

    read(arr, rows, cols);

    int** transposed = transpose(arr, rows, cols);

    display(transposed, cols, rows);
    
    dealloc(arr, rows);
    dealloc(transposed, cols);
    return 0;
}
