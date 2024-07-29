#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cin>>rows>>cols;
    int arr[3][3];

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>arr[i][j];
        }
    }

/*
1 2 3
4 5 6
7 8 9
*/
    for(int c=0; c<rows+cols-1; c++){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(i+j == c){
                    cout<<arr[i][j]<<" ";
                }
                else{
                    cout<<"* ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}