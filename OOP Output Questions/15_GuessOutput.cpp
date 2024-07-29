// Indicate the output of the following code

#include <iostream>
using namespace std;


class A{
public:
    void F1(){
        cout<<"F1() of class A"<<endl;
        F2(-5);
    }
    void F2(int num){
        cout<<"F2("<<num<<") of class A"<<endl;
    }
};

class B: public A{
public:
    void F1(){
        cout<<"F1() of class B"<<endl;
        F2(-10);
    }
    void F2(int num){
        cout<<"F2("<<num<<") of class B"<<endl;
    }
};

class C: public B{
public:
    void F2(int num){
        cout<<"F2("<<num<<") of class C"<<endl;
    }
};


int main()
{
    A* a = new B;
    a->F1();
    a->F2(23);
    B* b = new C;
    b->F1();
    b->F2(96);

    return 0;
}

/*
output:
    F1() of class A
    F2(-5) of class A
    F2(23) of class A
    F1() of class B
    F2(-10) of class B
    F2(96) of class B
*/