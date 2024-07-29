#include <iostream>
#include <ostream>
using namespace std;

class X
{
    int a;

public:
    X(){
       a = 0; 
    }
    void display(){
        cout<<"Value of a: "<<a<<endl;
    }
    void operator++(int){
        this->a++;
    }
    void operator--(int){
        a--;
    }
    void operator--(){
        --a;
    }
    void operator++(){
        ++a;
    }
};

int main(){
    X a;
    a++;
    a.display();
    a--;
    a.display();
    --a;
    a.display();
    ++a;
    a.display();

    return 0;
}