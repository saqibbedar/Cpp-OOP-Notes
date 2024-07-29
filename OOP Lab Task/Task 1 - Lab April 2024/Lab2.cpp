#include <iostream>
using namespace std;

class ABC{
    private:
    int a, b;
    public:
    ABC(int n){
        a = n;
    }
    void inputOfB(){
        b = 90;
    }
    void ftn(){
        cout<<"Value of a: "<< a <<endl
        << "Value of b: "<< b <<endl;
    }
};

int main()
{
    ABC a(10), b(20);
    a.inputOfB();
    b = a;
    b.ftn();
    return 0;
}