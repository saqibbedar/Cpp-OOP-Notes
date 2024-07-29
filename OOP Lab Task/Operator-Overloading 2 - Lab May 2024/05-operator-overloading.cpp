#include <iostream>
using namespace std;

class A{
    int a;
    public:
    A(){
        a=0;
        cout<<"Default constructor is called..."<<endl;
    }
    A(int x){
        a = x;
        cout<<"Params constructor is called..."<<endl;
    }
    A(const A& other){
        a = other.a;
        cout<<"Copy constructor is called..."<<endl;
    }
    ~A(){
        cout<<"Destructor is called..."<<endl;
    }

    A operator+(const A& other){
        return a + other.a;
    }

    int get()const{
        return a;
    }


    // A(int x=0):a(x){}
    
};

int main()
{
    A a = 10, b, c;
    c = a + b;
    cout<<c.get()<<endl;
    
    return 0;
}