#include <iostream>
using namespace std;

/*
    1 
    4 5 
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
        for(j = 1; j <= i; j++, index2++){
            cout<<arr[index1][index2]<<" ";
        }
        index2 = 0;
        cout<<endl;
    }
    return 0;
}