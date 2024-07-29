#include <iostream>
using namespace std;

class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class PublicDerived : public Base {
public:
    void show() {
        cout << "PublicDerived access:" << endl;
        cout << "publicVar: " << publicVar << endl; // Accessible
        cout << "protectedVar: " << protectedVar << endl; // Accessible
        // cout << "privateVar: " << privateVar << endl; // Not Accessible
    }
};

class ProtectedDerived : protected Base {
public:
    void show() {
        cout << "ProtectedDerived access:" << endl;
        cout << "publicVar: " << publicVar << endl; // Accessible
        cout << "protectedVar: " << protectedVar << endl; // Accessible
        // cout << "privateVar: " << privateVar << endl; // Not Accessible
    }
};

class PrivateDerived : private Base {
public:
    void show() {
        cout << "PrivateDerived access:" << endl;
        cout << "publicVar: " << publicVar << endl; // Accessible
        cout << "protectedVar: " << protectedVar << endl; // Accessible
        // cout << "privateVar: " << privateVar << endl; // Not Accessible
    }
};

int main() {
    Base base;
    PublicDerived pubDerived;
    ProtectedDerived protDerived;
    PrivateDerived privDerived;

    // Access in main for PublicDerived
    cout << "Accessing PublicDerived from main:" << endl;
    pubDerived.publicVar = 1; // Accessible
    // pubDerived.protectedVar = 2; // Not Accessible
    // pubDerived.privateVar = 3; // Not Accessible
    pubDerived.show();
    cout << endl;

    // Access in main for ProtectedDerived
    cout << "Accessing ProtectedDerived from main:" << endl;
    // protDerived.publicVar = 1; // Not Accessible
    // protDerived.protectedVar = 2; // Not Accessible
    // protDerived.privateVar = 3; // Not Accessible
    protDerived.show();
    cout << endl;

    // Access in main for PrivateDerived
    cout << "Accessing PrivateDerived from main:" << endl;
    // privDerived.publicVar = 1; // Not Accessible
    // privDerived.protectedVar = 2; // Not Accessible
    // privDerived.privateVar = 3; // Not Accessible
    privDerived.show();
    cout << endl;

    return 0;
}
