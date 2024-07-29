// What is static and dynamic polymorphism? Explain with examples.

/*
    Static polymorphism, also known as compile-time polymorphism, is achieved through method overloading and operator overloading. In static polymorphism, the method to be invoked is determined at compile time.

    Dynamic polymorphism, also known as run-time polymorphism, is achieved through method overriding using inheritance and virtual functions. In dynamic polymorphism, the method to be invoked is determined at run-time.

*/

#include <iostream>
using namespace std;

// Example of Static polymorphism

class Printer {
public:
    void print(int i) {
        cout << "Printing integer: " << i << endl;
    }

    void print(double d) {
        cout << "Printing double: " << d << endl;
    }

    void print(const string &s) {
        cout << "Printing string: " << s << endl;
    }
};

// Example of Dynamic polymorphism

class Base {
public:
    virtual void show() {
        cout << "Base class show() method" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show() method" << endl;
    }
};

int main() {
    
    cout<<"Example of static Polymorphism"<<endl;
    Printer printer;
    printer.print(5);
    printer.print(3.14);
    printer.print("Hello, world!");


    cout<<"\nExample of static Polymorphism"<<endl;
    Base* basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;
    // This will call the show() method of the Derived class
    basePtr->show();

    return 0;
}

