/*
    Virtual inheritance is a technique used in object-oriented programming to solve the "diamond problem," which arises in multiple inheritance scenarios. The diamond problem occurs when a class is derived from two classes that share a common base class, leading to ambiguity and redundancy.

    Diamond Problem:
          A
        /   \
       B     C
        \   /
          D

    Virtual inheritance solves this problem by ensuring that only one instance of the base class is shared among all derived classes. When B and C virtually inherit from A, D gets only one copy of A.

    When and Why Virtual Inheritance is Needed?

    Needed when multiple classes inherit from a common base class, and there is a potential for ambiguity and duplication.
*/


#include <iostream>
using namespace std;

// Example without virtual inheritance

class A {
public:
    int value;
};

class B : public A {
};

class C : public A {
};

// In this code, D has two copies of A, one from B and one from C. This ambiguity can be problematic.

class D : public B, public C {
};


// Example of virtual inheritance 

class Base {
public:
    int value;
};

class Derived1 : public virtual Base {
};

class Derived2 : public virtual Base {
};

class D4 : public Derived1, public Derived2 {
};


int main() {

    cout<<"Example without virtual Inheritance:"<<endl;
    D obj;
    // obj.value = 10; // Error: ambiguous which 'value' to use
    obj.B::value = 10; // Accessing value through B
    obj.C::value = 20; // Accessing value through C

    cout << "obj.B::value: " << obj.B::value << endl;
    cout << "obj.C::value: " << obj.C::value << endl;

    cout<<"Example of virtual Inheritance:"<<endl;
    D4 d;
    d.value = 10; // no ambiguity 
    cout<<"d.value: "<<d.value<<endl;

    return 0;
}
