#include <iostream>
using namespace std;

int* createArray(int size){
    int *arr = new int[size];
    return arr;
}

int** create2dArray(int rows, int cols){
    int **arr = new int*[rows];
    for(int i = 0; i<rows; i++){
        *(arr+i) = new int[cols];
    }
    return arr;
}

void readArray(int** arr, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            // cin>>arr[i][j];
            cin>>*(*(arr+i)+j);
        }
    }
}

void display(int **arr, int rows, int cols){
    // if square matrix 
    if(rows == cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(i+j == rows - 1) // if sqr matrix
                cout<<*(*(arr+i)+j)<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    } // if not square matrix
    else{
        for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(i+j == cols - 1) // if not sqr matrix
                cout<<*(*(arr+i)+j)<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    }

}

int main()
{
    int rows, cols;
    cout<<"Enter rows: ";
    cin>>rows;
    cout<<"Enter cols: ";
    cin>>cols;

    int **arr = create2dArray(rows, cols);
    readArray(arr, rows, cols);
    display(arr, rows, cols);

    for(int i=0; i<rows; i++){
        delete[] *(arr+i);
    }

    delete[] arr;
    return 0;
}

/*
let's walk through the iterations for a 3x3 matrix. The matrix indices start from 0, so for a 3x3 matrix, the indices for rows and columns will be 0, 1, and 2.

Here's how the iterations will go:


For i=0, j=0: i+j = 0+0 = 0. This is not equal to n-1 (which is 3-1=2), so this element is not on the anti-diagonal.

For i=0, j=1: i+j = 0+1 = 1. This is not equal to n-1, so this element is not on the anti-diagonal.

For i=0, j=2: i+j = 0+2 = 2. This is equal to n-1, so this element is on the anti-diagonal.

Next row:


For i=1, j=0: i+j = 1+0 = 1. This is not equal to n-1, so this element is not on the anti-diagonal.

For i=1, j=1: i+j = 1+1 = 2. This is equal to n-1, so this element is on the anti-diagonal.

For i=1, j=2: i+j = 1+2 = 3. This is not equal to n-1, so this element is not on the anti-diagonal.

Last row:


For i=2, j=0: i+j = 2+0 = 2. This is equal to n-1, so this element is on the anti-diagonal.

For i=2, j=1: i+j = 2+1 = 3. This is not equal to n-1, so this element is not on the anti-diagonal.

For i=2, j=2: i+j = 2+2 = 4. This is not equal to n-1, so this element is not on the anti-diagonal.

So, for a 3x3 matrix, the elements on the anti-diagonal are those at positions (0,2), (1,1), and (2,0).
*/