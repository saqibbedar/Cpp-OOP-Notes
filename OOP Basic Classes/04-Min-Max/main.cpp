#include "min-max.hpp"

const int size = 5;

int main(){
    int arr[::size] = {10, 20, 30, 40, 50};
    MinMax a;
    int result = a.max(arr, ::size);
    cout<<"Max number in array is: "<<result<<endl;
    result = a.min(arr, ::size);
    cout<<"Min number in array is: "<<result<<endl;
    return 0;
}