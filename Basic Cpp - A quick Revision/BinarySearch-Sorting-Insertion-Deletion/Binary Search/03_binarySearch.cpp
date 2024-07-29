#include<iostream>
using namespace std;

const int SIZE = 6;

void binarySearch(int arr[], int l,int r,int val) {
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (val > arr[mid])
            l = mid + 1;
        else if (val < arr[mid])
            r = mid - 1;
        else {
            cout << "Value at index:" << mid << endl;
            int search = mid;
            while (arr[search] == arr[search - 1]) {
                search = search - 1;
                cout << "value at index:" << search << endl;
            }
            while (arr[mid] == arr[mid + 1]) {
                mid = mid + 1;
                cout << "value at index:" << mid << endl;
            }
            break;
        }
    }
}

int main() {
    int arr[SIZE] = { 1,8,8,8,9,10 };
    binarySearch(arr, 0, 6,8);
}
