/* 
    Question: Can a const member function call a non-const member function? Why / Why not?

    Answer: No, a const member function cannot call a non-const member function directly because a const member function guarantees not to modify the object's state. Calling a non-const member function from within a const member function would violate this guarantee since non-const member functions can modify the object's state.
*/

#include <iostream>
using namespace std;

class MyClass {
    int value;

public:
    MyClass(int v) : value(v) {}

    void nonConstFunction() {
        value += 10;
        cout << "Non-const function called. Value: " << value << endl;
    }

    void constFunction() const {
        cout << "Const function called. Value: " << value << endl;
        // nonConstFunction(); // This will cause a compile error
    }
};

int main() {
    MyClass obj(5);

    obj.nonConstFunction();
    obj.constFunction();

    return 0;
}

// When you try to compile this code, you will get an error because the constFunction is attempting to call nonConstFunction, which is not allowed.