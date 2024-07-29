#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout<<"Enter rows: ";
    cin>>rows;
    cout<<"Enter cols: ";
    cin>>cols;

    // dynamic memory allocation
    int **arr = new int*[rows];
    for(int i=0; i<rows; i++){
        arr[i] = new int[cols];
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Diagonal : ";
    for(int i=0; i<rows; i++){
        cout<<arr[i][i]<<"\t";
    }
    cout<<'\n';
    cout<<"Anti diagonal : ";
    for(int i=0; i<rows; i++){
        cout<<arr[i][cols-1-i]<<'\t';
    }

    // deallocation
    for(int i=0; i<rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}