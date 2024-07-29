#include <iostream>
using namespace std;

class A{
    int a, b;
    public:
    A(): a(0), b(0){}
    A(int x, int y): a(x), b(y){}
    A(const A& other){
        a = other.a;
        b = other.b;
    }
    void display() const{
        cout<<"a = "<<a<<", b = "<<b<<endl;
    }
    void hello() const {
        cout<<"Hello from A class, ftx hello is called!"<<endl;
    }
};

int main()
{
    A obj1(10, 20), obj2;
    cout<<"obj1: ";
    obj1.display();
    obj2 = obj1;
    cout<<"obj2: ";
    obj2.display();
    obj1.hello();
    return 0;
}