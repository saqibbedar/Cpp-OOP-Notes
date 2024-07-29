/*
    Casting in C++ is a way to convert a variable from one type to another. 

    Types of Casting:

    Static Cast (static_cast): This is the most common type of casting. It is used for converting between compatible types, such as converting an integer to a float, or between pointer types in an inheritance hierarchy.

    Dynamic Cast (dynamic_cast): This cast is used for safe downcasting, typically in a class hierarchy where you want to ensure the cast is valid at runtime. It requires the presence of virtual functions in the base class.

    Const Cast (const_cast): This cast is used to add or remove const from a variable. It can be useful when dealing with APIs that require non-const arguments.

    Reinterpret Cast (reinterpret_cast): This cast is used for low-level reinterpreting of the bit pattern of an object. It is typically used for converting between different pointer types.

*/

#include <iostream>
using namespace std;

// Dynamic Cast

class Base {
public:
    virtual void display() { cout << "Base class" << endl; }
};

class Derived : public Base {
public:
    void display() override { cout << "Derived class" << endl; }
};


// Const typeCasting

void print(const int* ptr) {
    // Using const_cast to remove constness
    int* modifiablePtr = const_cast<int*>(ptr);
    *modifiablePtr = 20;
}

int main() {

    //(1) Example of static_cast for converting int to double
    cout<<"Static TypeCasting example: "<<endl;
    int a = 10;
    double b = static_cast<double>(a);

    cout << "Integer: " << a << endl;
    cout << "Double: " << b << endl;

    cout<<"---------------------------------------"<<endl;


    //(2) Example of Dynamic casting
    cout<<"Dynamic TypeCasting example: "<<endl;
    Base* basePtr = new Derived;
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        derivedPtr->display(); // Safe to use derivedPtr
    } else {
        cout << "Failed to cast" << endl;
    }

    delete basePtr;

    cout<<"---------------------------------------"<<endl;


    //(3) Example of const TypeCasting
    cout<<"Dynamic TypeCasting example: "<<endl;
    const int value = 10;
    cout << "Before: " << value << endl;
    print(&value); // Undefined behavior (just for demonstration)
    cout << "After: " << value << endl;

    cout<<"---------------------------------------"<<endl;


    //(4) Example of Reinterpret Cast
    cout<<"Reinterpret TypeCasting example: "<<endl;
    int a = 65;
    // Using reinterpret_cast to convert int pointer to char pointer
    char* charPtr = reinterpret_cast<char*>(&a);

    cout << "Integer: " << a << endl;
    cout << "Char: " << *charPtr << endl; // ASCII character 'A'

    cout<<"---------------------------------------"<<endl;

    return 0;
}
