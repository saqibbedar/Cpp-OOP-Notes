/* 
    a. Is it safe if a function which is public member of a class has a return type of int & and returns a member variable of the class? Why/Why not?

    b. Will it be safe if the function in the question above is private? Why?

    Answer (a): No, it is generally not safe. When a function returns a reference to a member variable, it exposes that variable directly to the outside world. This allows external code to modify the internal state of the class without any control or validation, which can break encapsulation and lead to undefined behavior. Moreover, if the object of the class is destroyed, the reference will become dangling, leading to potential crashes or undefined behavior if it is accessed afterward.
*/

#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    int& getValue() {
        return value; // Returning a reference to a private member variable
    }
};

int main() {
    MyClass obj(10);
    int& ref = obj.getValue(); // ref is now a reference to obj.value
    ref = 20; // This modifies obj.value directly

    cout << "obj.value: " << obj.getValue() << endl;

    return 0;
}


/*
    Answer(b): Yes, it is safe. The function is private, and it is not exposed to the outside world. Therefore, it is safe to return a reference to a member variable without any control or validation.
*/

class MyClass {
private:
    int value;

    int& getValue() {
        return value; // Returning a reference to a private member variable
    }

public:
    MyClass(int v) : value(v) {}

    void modifyValue() {
        int& ref = getValue(); // Safe within the class
        ref = 20;
    }

    void printValue() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    MyClass obj(10);
    obj.modifyValue();
    obj.printValue(); // Safe usage within the class

    return 0;
}

/*
    Conclusion:

    Public Member Function: Returning a reference to a member variable through a public member function is generally unsafe due to potential direct modification and dangling reference issues.

    Private Member Function: It is safer to return a reference to a member variable through a private member function because it restricts access to within the class. However, care must still be taken to avoid dangling references and ensure proper object lifetime management.
*/