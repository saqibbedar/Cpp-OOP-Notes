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
        // int temp = a + x.a; return ABC(temp);
        return ABC(a + x.a);
    }
    ABC operator+=(ABC x){
    //  a+=x.a;
     return ABC(a+= x.a);   
    }
    ABC operator*=(ABC x){
        a*= x.a;
        return ABC(a);
    }
    // void ftn(){
    //     ABC obj = *this;
    //     int a = 0;
    //     int b = &a;
    //     int c = *b;
    // }

};

int main(){
    ABC a = 10, b;
    ++a;
    b = a; 
    b.display();
    ABC sum = a+b;
    sum.display();
    ABC sum2;
    sum2+= b;
    sum2.display();
    ABC z = 2;
    z*= sum2;
    z.display();
    
    return 0;
}