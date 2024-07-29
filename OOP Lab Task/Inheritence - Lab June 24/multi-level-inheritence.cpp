#include <iostream>
using namespace std;

class A{
    public:
    A(){cout<<"Hello from A class"<<endl;}
    void ftn1(){
        cout<<"Message from A"<<endl;
    }
};
class B : public A{
    public:
    B(){cout<<"Hello from B class"<<endl;}
    void ftn2(){
        cout<<"Message from B"<<endl;
    }
};
class C : public B{
    public:
    C(){cout<<"Hello from C class"<<endl;}
    void ftn3(){
        cout<<"Message from C"<<endl;
    }
};
class D : public C{
    public:
    D(){cout<<"Hello from D class"<<endl;}
    void ftn4(){
        cout<<"Message from D"<<endl;
    }
};


int main()
{
    D obj;
    obj.ftn1();
    obj.ftn2();
    obj.ftn3(); 
    obj.ftn4();

    return 0;
}