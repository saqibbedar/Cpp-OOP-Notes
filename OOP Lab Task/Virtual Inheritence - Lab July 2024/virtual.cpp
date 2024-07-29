#include <iostream>
using namespace std;

class Base{
    public: 
    virtual void show(){
        cout<<"Base \n";
    }
};
class Derived1 : public Base{
    public: 
    void show(){
        cout<<"Derived 1\n";
    }
};
class Derived2 : public Base{
    public: 
    void show(){
        cout<<"Derived 2\n";
    }
};

int main(){
    Derived1 d1;
    Derived2 d2;
    Base *ptr;
    ptr = &d1;
    ptr->show();
    ptr = &d2;
    ptr->show();

    return 0;
}