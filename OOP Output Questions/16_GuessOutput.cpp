// Indicate the output of the following code

#include <iostream>
using namespace std;


class A{
public:
    void F1(){
        cout<<"F1() of class A"<<endl;
        F2(-5);
    }
    virtual void F2(int num){
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

void F1F2(A* a){
    a->F1();
    (dynamic_cast<C*>(a))->F2(99);
    (dynamic_cast<C*>(a))->F1();
}

int main()
{
    B* b = new C;
    F1F2(b);
    b->F1();

    return 0;
}

/*
output:
    F1() of class A
    F2(-5) of class C
    F2(99) of class C
    F1() of class B
    F2(-10) of class C
    F1() of class B
    F2(-10) of class C
*/