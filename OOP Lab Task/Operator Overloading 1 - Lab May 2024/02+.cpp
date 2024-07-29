#include <iostream>
#include <ostream>
using namespace std;

class ABC {
    int a;
public:
    ABC(){
       a = 0; 
    }
    void display(){
        cout<<"Value of object is: "<<a<<endl;
    }
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
    ABC operator+(ABC x){
        return ABC(a + x.a);
    }

};

int main(){
    ABC a = 10, b;
    ++a;
    b = a; 
    b.display();
    ABC sum = a+b;
    sum.display();

    return 0;
}