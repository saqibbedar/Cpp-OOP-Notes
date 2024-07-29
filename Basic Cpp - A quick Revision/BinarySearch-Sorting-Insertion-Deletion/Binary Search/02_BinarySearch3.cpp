#include <iostream>
using namespace std;

const int SIZE = 10;

// Binary Search
void binarySearch(int arr[], int length, int target){
    int first = 0;
    int last = length - 1;
    bool flag = false;
    while(first <= last){
        int mid = first + (last - first) / 2;
        if (arr[mid] == target) {
            std::cout << target << " found at index " << mid << std::endl;
            flag = true;

            int temp = mid - 1;
            while (temp >= 0 && arr[temp] == target) {
                std::cout << target << " found at index " << temp << std::endl;
                temp--;
            }

            temp = mid + 1;
            while (temp < length && arr[temp] == target) {
                std::cout << target << " found at index " << temp << std::endl;
                temp++;
            }
            break;
        } else if (target < arr[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    if(!flag){
        std::cout << "Number does not exist in array" << std::endl;
    }
}

// void binarySearch(int arr[], int size, int target) {
//     int first = 0;
//     int last = size - 1;
 
//     bool found = false;

//     while (first <= last) {
//         int mid = first + (last - first) / 2;
//         if (arr[mid] == target) {
//             cout << mid << " ";
//             found = true;
//             break;
//         } else if (target < arr[mid]) {
//             last = mid - 1;
//         } else {
//             first = mid + 1;
//         }
//     }

//     if (!found) {
//         cout << "Target not found";
//     }

// }

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    int target = 4;
    binarySearch(arr, SIZE, target);

    return 0;
}
