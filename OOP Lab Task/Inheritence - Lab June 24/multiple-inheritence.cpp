#include <iostream>
using namespace std;

class A{
protected:
    int a;
    public:
    A(){cout<<"Hello form A class"<<endl;}
    A(int x):a(x){
        cout<<"A class a = "<<a<<endl;
    }
    void msg(){
        cout<<"Message from A"<<endl;
    }
};
class B{
protected:
    int b;
    public:
    B(){cout<<"Hello form B class"<<endl;}
    B(int x):b(x){
        cout<<"B class b = "<<b<<endl;
    }
    void msg(){
        cout<<"Message from B"<<endl;
    }
};
class C : public A, public B {
    public:
    C (){cout<<"Hello form C class"<<endl;}
    C(int x, int y, int z): A(z), B(x){
        cout<<"C class parameterized constructor: "<<a<<" "<<b<<" "<<z<<endl;
    }
};

int main()
{
    C xyz;
    C(10, 20, 30);
    // xyz.msg(); this will throw the error as both functions are defined with same name and same parameters, so to solve this we will use scop resolution operator
    xyz.A::msg();
    xyz.B::msg();
    
    return 0;
}