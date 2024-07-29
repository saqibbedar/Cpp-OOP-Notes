#include <iostream>
using namespace std;

class Base{
    public: 
    void show(){
        cout<<"Base \n";
    }
};
class Derived1 : public Base{
    public: 
    void show(){
        cout<<"Derived \n";
    }
};
class Derived2 : public Base{
    public: 
    void show(){
        cout<<"Derived \n";
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

/*
The above program will call the same base class's function but we will make the function virtual.

class Base{
    public: 
    virtual void show(){
        cout<<"Base \n";
    }
};

*/