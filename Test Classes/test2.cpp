#include <iostream>
using namespace std;
class A{

};
class B{

};
class C : public A {

};

int main()
{
    // A* a = new B; error because can't create a pointer until it B derive from A
    A* a = new C; // no error 

    return 0;
}