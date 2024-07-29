#include <iostream>
using namespace std;

int main()
{
    int arr[3][3];
    for(int i= 0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }   
    for(int i= 0; i<3; i++){
        for(int j=0; j<3; j++){
            i==j || i+j== 3-1 ? cout<<arr[i][j]<<" " : cout<<" ";
        }
        cout<<endl;
    } 
    return 0;
}