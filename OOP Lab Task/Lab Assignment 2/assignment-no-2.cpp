#include <iostream>
using namespace std;

class Base{
// setting protected to a in derived class
protected:
    int a;
public:
    // constructors
    Base(): a(0){} 
    Base(int x): a(x){} // parametrized constructor
    ~Base(){}

    // setters and getters
    void setA(int x){a = x;}
    int getA(){return a;}

    // operator overloading
    Base operator+=(const Base &obj){
        return Base(a += obj.a);
    }
    Base operator++(){
        return Base(a++);
    }
    bool operator>(const Base &obj){
        return a > obj.a;
    }
    bool operator==(const Base &obj){
        return a == obj.a;
    }
    Base operator/(const Base &obj){
        if(obj.a == 0){
            cout << "Cannot divide by zero" << endl;
            return Base(0);
        }
        return Base(a / obj.a);
    }
    int operator[](int index){
        return a + index;
    }
    
    // friend function
    friend ostream &operator<<(ostream &out, const Base &obj){
        out << obj.a;
        return out;
    }
    friend istream &operator>>(istream &in, Base &obj){
        in >> obj.a;
        return in;
    }
};

class Derived : public Base{ 
public:
    Derived(int x): Base(x){}

    // operator overloading
    Derived operator-=(const Derived &obj){
        return Derived(a -= obj.a);
    }
    Derived operator--(){
        return Derived(--a);
    }
    bool operator<(const Derived &obj){
        return (a < obj.a);
    }
    bool operator==(const Derived &obj){
        return (a == obj.a);
    }
    Derived operator*(const Derived &obj){
        return (a * obj.a);
    }
    int operator[](int index){
        return a - index;
    }
};

int main(){

    Derived obj1(5), obj2 = 10;
    ++obj1;
    cout<<obj1.getA()<<endl; // 6
    obj1+=obj2;
    cout<<obj1.getA()<<endl; // 16

    obj1 > obj2 ? cout<<"True"<<endl : cout<<"False"<<endl; // True

    obj1 == obj2 ? cout<<"True"<<endl : cout<<"False"<<endl; // False

    // cout<<obj2/obj1<<endl; // 1

    cout<<obj1[3]<<endl; // 13

    return 0;
}
