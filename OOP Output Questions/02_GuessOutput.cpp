// consider following code. write down the output when main() is executed.

#include <iostream>
using namespace std;

class A {
    int hold;

public:
    A(int hold = 0) {
        this->hold = hold;
    }
    virtual void f() {
        hold += 2;
        cout << "hold: " << hold << endl;
    }
};

class B : public A {
    int hold;

public:
    B(int hold = 0) : A(hold) {
        this->hold = hold;
    }
    virtual void f() = 0; // Pure virtual function
    void g() {
        hold += 3;
        cout << "hold: " << hold << endl;
    }
};

int main() {

    // Error: object of abstract class type "B" is not allowed
    // B obj(5); // This will cause a compilation error because B is abstract because it has pure virtual function, therefore we cannot create a object of its class and result would be runtime error.
    // obj.g();
    // obj.f();

    return 0;
}
