#include <iostream>

void binarySearch(int arr[], int size, int target) {
    int first = 0;
    int last = size - 1;

    bool found = false;

    while (first <= last) {
        int mid = first + (last - first) / 2;
        if (arr[mid] == target) {
            std::cout << mid << " ";
            found = true;
            break;
        } else if (target < arr[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }

    if (!found) {
        std::cout << "Target not found";
    }

    std::cout << std::endl;
}

int main() {
    int arr[5] = {1, 2, 2, 2, 5};
    int search;
    std::cout<<"Enter a value to search in array: ";
    std::cin>>search;

    std::cout << "Indices of "<<search<<" are: ";
    binarySearch(arr, 5, search);

    return 0;
}
