#include <iostream>
#include <ostream>
using namespace std;

class ABC
{
    int a;

public:
    ABC(){
       a = 0; 
    }
    void display(){
        cout<<"Value of a: "<<a<<endl;
    }
    
    // ABC operator--(){
    //     --a;
    //     ABC x;
    //     x.a = a;
    //     return x;
    // }
    // ABC operator++(){
    //     ++a;
    //     ABC temp;
    //     temp.a = a;
    //     return temp;
    // }
    ABC(int x){
        a = x;
    }
    ABC operator--(){
        --a;
        return ABC(a);
    }
    ABC operator++(){
        ++a;
        return ABC(a);
    }
};

int main(){
    ABC a = 10, b;
    ++a; // a becomes 11
    b = a; // b is assigned with return value of a
    b.display(); // displaying to test the returned value
    --a; // -1 from a object // 10
    a.display(); // display a output: 10

    return 0;
}