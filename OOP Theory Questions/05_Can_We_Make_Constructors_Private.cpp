/*
    Question: Can we make the constructor of a class as private? Why/Why not?

    Answer: Yes, we can make constructors of a class private in C++. This technique is used for a few specific purposes, such as implementing the Singleton pattern, controlling the object creation process, or preventing the creation of instances of a class.

    1. Singleton Pattern: Ensuring that only one instance of the class can be created.
    2. Factory Method: Controlling object creation and returning instances through static methods.
    3. Preventing Object Creation: Ensuring that objects of the class cannot be created directly.
*/

// 17, 18, 23, 24, 25, 28 kepler law questions 


// Preventing Instantiation

#include <iostream>
using namespace std;

class Utility {
private:
    // Private constructor to prevent instantiation
    Utility() {}

public:
    // Static utility function
    static void printMessage(const string& message) {
        cout << message << endl;
    }
};

int main() {
    // Utility u; // Error: 'Utility::Utility()' is private within this context

    Utility::printMessage("Hello, world!");  // Output: Hello, world!

    return 0;
}
