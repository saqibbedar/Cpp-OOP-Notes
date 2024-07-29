// Operator overloading: It is feature in C++ where we can overload operators for user defined data types.Operator overloading is used to overload or redefines most of the operators available in C++. It is used to perform operation on user-defined data type. For example '+' operator can be overloaded to perform addition on the objects in addition to its native data types.

#include <iostream>
using namespace std;

class OperatorOverload{
    int a;
    public:
    // OperatorOverload():a(0){}
    // OperatorOverload(int x):a(x){}
    // copy constructor
    // OperatorOverload(const OperatorOverload &obj):a(obj.a){}

    OperatorOverload(){
        a = 0;
    }
    OperatorOverload(int x){
        a = x;
    }
    OperatorOverload(const OperatorOverload &obj){
        a = obj.a;
    }

    OperatorOverload operator+(const OperatorOverload &obj){
        return OperatorOverload(a+obj.a);
    }
    OperatorOverload operator-(const OperatorOverload &obj){
        return OperatorOverload(a - obj.a);
    }
    OperatorOverload& operator++();
    OperatorOverload& operator++(int);
    OperatorOverload& operator--();
    OperatorOverload& operator--(int);

    // friend functions 
    friend ostream& operator<<(ostream &out, const OperatorOverload &obj);

};

ostream& operator<<(ostream &out, const OperatorOverload &obj){
    out<<obj.a;
    return out;
}

int main(){
    OperatorOverload obj1 = 10;
    OperatorOverload obj2 = 20;

    OperatorOverload obj3 = obj1 + obj2;
    OperatorOverload obj4 = obj1 - obj2;

    cout<<obj3<<endl;
    cout<<obj4<<endl;

    return 0;
} 