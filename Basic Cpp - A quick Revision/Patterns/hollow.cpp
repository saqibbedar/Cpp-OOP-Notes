#include <iostream>
using namespace std;

/*
    1 2 3
    4   6 
    7 8 9 
*/

int main()
{
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int i, j, size = 3;

    int index1 = 0, index2 = 0;

    for(i = 1; i<=size; i++, index1++){
        for(j = 1; j <= size; j++, index2++){
            if(i == 1 || i == size || j == 1 || j == size){
            cout<<arr[index1][index2];
            }else{
                cout<<" ";
            }
        }
        index2 = 0;
        cout<<endl;
    }
    return 0;
}