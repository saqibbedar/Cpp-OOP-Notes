// friend functions and friend classes
// This program demonstrates the use of friend functions to access private members of multiple classes. The abc function is a friend of all three classes, so it can access their private members directly.

#include <iostream>
using namespace std;


class B;
class C;
class A{
    int a;
    public:
    friend int fun(A obj);
    friend void abc(A &, B &, C &);
    A(int x){
        a = x;
    }
};

class B{    
    int b;
    public:
    friend void abc(A &, B &, C &);
    B(int x){
        b = x;
    }
};

class C{   
    int c;
    public:
    friend void abc(A &, B &, C &);
    C(int x){
        c = x;
    }
};

void abc(A &obj, B &obj1, C &obj2){
    cout<<"sum of three private numbers is : "<<(obj.a+obj1.b+obj2.c)<<endl;
}


int main()
{
    A obj(10);
    B obj1(20);
    C obj2(30);
    // abc(obj, obj1, obj2);
    abc(obj, obj1, obj2);
    return 0;
}