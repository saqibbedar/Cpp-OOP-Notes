/*
assume that the array can only store even numbers. Write both implementations of [] operator. Throw exception if the index is out of range. Write try block in main and create array object. Use both implementations of [] operator to throw exceptions when index is out of range or when user tries to assign odd value in the array element. Write catch blocks to handle these exceptions.
*/

#include <iostream>
#include <string>
using namespace std;

// For handling exceptions(Errors)
class Error {
    string message;
public:
    explicit Error(const string& msg) : message(msg) {}
    void showError() const {
        cout << "Error: " << message << endl;
    }
};

// EvenArray class to store only even numbers
class EvenArray {
    int* arr;
    int size;

public:
    EvenArray(int s) : size(s) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = 0; // Initialize with 0, which is an even number
        }
    }

    ~EvenArray() {
        delete[] arr;
    }

    // Overload the [] operator for accessing
    int operator[](int index) const {
        if (index < 0 || index >= size) {
            throw Error("Index out of range.");
        }
        return arr[index];
    }

    // Overload the [] operator for assigning
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw Error("Index out of range.");
        }
        return arr[index];
    }

    // Set function with check for even number
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw Error("Index out of range.");
        }
        if (value % 2 != 0) {
            throw Error("Only even numbers can be stored.");
        }
        
        arr[index] = value;
    }
};

int main() {
    EvenArray arr(5);

    arr.set(0, 2); 
    arr.set(1, 4); 

    arr[2] = 6; 

    cout << arr[0] << endl;
    cout << arr[1] << endl;

    try
    {
        cout << arr[5] << endl; // "Index out of range."
    }
    catch(const Error& e)
    {
        e.showError();
    }
        
    cout << arr[2] << endl;

    try {
        arr[3] = 5; // Throws "Only even numbers can be stored."
    } catch (const Error& e) {
        e.showError();
    }

    return 0;
}
