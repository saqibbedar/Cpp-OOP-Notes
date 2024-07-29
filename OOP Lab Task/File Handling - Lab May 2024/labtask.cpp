#include <iostream>
#include <fstream>
using namespace std;

int** create2dArray(int rows, int cols){
    int **arr = new int*[rows];
    for(int i=0; i<rows; i++){
        *(arr+i) = new int[cols];
    }
    return arr;
}

void dealloc(int** arr, int rows){
    for(int i=0; i<rows; i++){
        delete[] *(arr+i);
    }
    delete arr;
}


int main()
{
    // int rows, cols;
    // cout<<"Enter rows and cols"<<endl;
    // cin>>rows>>cols;

    // int **arr = create2dArray(rows, cols);

    // take input
    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<cols; j++){
    //         cout<<"Enter values at index ["<<i<<"]"<<"["<<j<<"] : ";
    //         cin>>*(*(arr+i)+j);
    //     }
    // }

    // ofstream write;
    // write.open("file.txt", ios::app); // write data to file
    
    // // write data to file
    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<cols; j++){
    //         write << *(*(arr+i)+j)<<" ";
    //     }
    //     write<<endl;
    // }

    ifstream read;
    read.open("file.txt");
    char c;
    // read data from file
    while(read.get(c)){
        cout<<c;
    }

    read.close(); 
    // dealloc(arr, rows); // deallocate memory
    // write.close(); // close file
    return 0;
}