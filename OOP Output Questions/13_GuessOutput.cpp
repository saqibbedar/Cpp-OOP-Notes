// What is the ouput of the following program segment?

#include <iostream>
using namespace std;

class A{
    int a;
public:
    A(int x = 1) {a = x;}
    int getA(){return a;}
    virtual void f(){ a+= 2;}
    virtual int g() 
    { 
        a+=1; 
        return a;
    }
    int h()
    {
        f();
        return a; 
    }
    int j() { return g() + a;}
};

class B : public A {
    int b;
public: 
    void f() { b+= 10; }
    void j() { b+= getA(); }
    int g() { b+= 5; return b; }
};

int main()
{
    A obj1;
    B obj2;
    A* a = &obj1;

    cout<< a->h() <<endl;
    cout<< a->j() <<endl;
    cout<< a->g() <<endl;

    a = &obj2;

    cout<< a->h() <<endl;
    cout<< a->j() <<endl;
    cout<< a->g() <<endl;

    return 0;
}

/*
output:
    3
    8
    5
    1
    1972601469
    1972601473
*/