#include <iostream>
using namespace std;

class Quiz{
    int num;
    public:
    Quiz(int x): num(x){
        cout<<"In constructor "<<num<<endl;
    }
    ~Quiz(){
        cout<<"In destructor "<<num<<endl;
    }
};

Quiz a(1);

void Create(){
    Quiz b(2);
    Quiz c(3);
}

Quiz d(4);

int main(){
    Quiz e(5);
    Create();
    Quiz f(6);

    return 0;
}

/* 
output:
    In constructor 1
    In constructor 4
    In constructor 5
    In constructor 2
    In constructor 3
    In destructor 3
    In destructor 2
    In constructor 6
    In destructor 6
    In destructor 5
    In destructor 4
    In destructor 1
*/