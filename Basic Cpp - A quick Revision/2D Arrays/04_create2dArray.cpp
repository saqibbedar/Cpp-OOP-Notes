#include <iostream>
using namespace std;

void read(int** arr, int rows, int* cols){
    for(int i= 0; i<rows; i++){
        for(int j=0; j<cols[i]; j++){
            cout<<"Enter array element at index ["<<i<<"]"<<"["<<j<<"] : ";
            cin>>arr[i][j];
        }
    }
}

void display(int** arr, int rows, int* cols){
    for(int i= 0; i<rows; i++){
        for(int j=0; j<cols[i]; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dealloc(int** arr, int rows){
    for(int i=0; i<rows; i++){
        delete[] arr[i];
    }
    delete arr;
}

int main(){
    int rows;
    cout<<"Enter rows: ";
    cin>>rows;

    int** arr = new int*[rows]; // 2d dynamic Array
    int getCols;
    int* colSizeHolder = new int[rows]; // for holding cols size

    // allocating dynamic memory
    for(int i=0; i<rows; i++){
        cout<<"\nEnter cols size: ";
        cin>>getCols; // read cols size
        colSizeHolder[i] = getCols; // store cols size
        arr[i] = new int[getCols]; // allocating cols size
    }

    read(arr, rows, colSizeHolder); // read array
    display(arr, rows, colSizeHolder); // display array

    dealloc(arr, rows);
    delete[] colSizeHolder;
    return 0;
}


// practice
int** creat2dArray(int rows, int cols){
    int** arr = new int*[rows];

    for(int i=0; i<rows; i++){
        arr[i] = new int[cols];
    }

    return arr;
}
// allocate 1d array
int* alloc(int rows){
    int* arr = new int[rows];
    return arr;
}

// dealloc 2d array

void dealloc2d(int** arr, int rows){
    for(int i = 0; i<rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

int** my2d(int cols, int rows){
    int **arr = new int*[rows];
    for(int i=0; i<rows; i++){
        *(arr+i) = new int[cols];
    }
    return arr;
}

int** myarray(int rows, int cols){
    int **arr = new int*[rows];
    for(int i=0; i<rows; i++){
        arr[i] = new int[cols];
    }
    return arr;
}

void deallocate(int **arr, int rows){
    for(int i=0; i<rows;i++){
        delete[] arr[i]; 
    }
    delete[] arr;
}