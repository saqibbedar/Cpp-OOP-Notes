#include <iostream>
using namespace std;

class checkingOutput{
    int num;
    public:
    checkingOutput(int x ): num(x){
        cout<<"In constructor "<<x<<endl;
    }
    ~checkingOutput(){
        cout<<"In destructor "<<num<<endl;
    }
};

const checkingOutput a(1);

void create(){
    checkingOutput b(2);
    static checkingOutput c(3);
    checkingOutput d(4);
}

int main()
{
    checkingOutput e(5);
    static checkingOutput f(6);
    create();
    checkingOutput g(7);
    
    return 0;
}

/*
output:
    In constructor 1
    In constructor 5
    In constructor 6
    In constructor 2
    In constructor 3
    In constructor 4
    In destructor 4
    In destructor 2
    In constructor 7
    In destructor 7
    In destructor 5
    In destructor 3
    In destructor 6
    In destructor 1
*/