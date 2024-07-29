#include <iostream>
using namespace std;

class A{
    public:
    A(){
        cout<<"A constructor"<<endl;
    }
};

class B{
    A a;
    public:
    B(){
        cout<<"B constructor"<<endl;
    }

};

int main(){
    B b;
    return 0;
}