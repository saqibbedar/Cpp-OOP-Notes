#include <iostream>

void binarySearch(int arr[], int size, int target) {
    int left = -1;  // Initialize left boundary to -1
    int right = -1; // Initialize right boundary to -1

    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            if (left == -1) {
                left = i;
            }
            right = i;
        }
    }

    if (left != -1) {
        std::cout << "Indices of target value: " << left << " to " << right;
    } else {
        std::cout << "Target not found";
    }
}

int main() {
    int arr[5] = {1, 2, 2, 2, 5};

    std::cout << "Indices of target value: ";
    binarySearch(arr, 5, 2);

    return 0;
}
