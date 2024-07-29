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

    int i, j, k, size = 3;

    // matrix index handlers
    int index1 = 0, index2 = 0;

    for(i = 1; i <= size; i++, index1++){
        for(j = 1; j<= size-i; j++){
            cout<<" "; 
        }
        for(k = 1; k <= i; k++, index2++){
            cout<<arr[index1][index2];
        }
        index2 = 0; // reset to zero for columns{0,1,2}
        cout<<endl;
    }

    return 0;
}
