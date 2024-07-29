/*
    Question: Can a non-const member function call a const member function? Why / Why not?

    Answer: Yes, a non-const member function can call a const member function. This is because calling a const member function from within a non-const member function does not violate any guarantees. A const member function promises not to modify the object's state, which is perfectly acceptable in any context, including from within non-const member functions.

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
        constFunction(); // Calling a const member function
    }

    void constFunction() const {
        cout << "Const function called. Value: " << value << endl;
    }
    
};

int main() {
    MyClass obj(5);

    obj.nonConstFunction();

    return 0;
}

/*
output: 
    Non-const function called. Value: 15
    Const function called. Value: 5
*/