#pragma once
#include<iostream>
using namespace std;

class Overloading{
    int a, b;
    public: 
    Overloading(int a, int b){
        this->a = a;
        this->b = b;
    }
    Overloading(){
        a = 0;
        b = 0;
    }
    Overloading(int a){
        this->a = a;
    }
    Overloading(const Overloading& o){
        a = o.a;
        b = o.b;
    }
    const void operator-(const Overloading& c)const{
        cout<<"The difference is: "<<a-c.b<<endl;
    }
};