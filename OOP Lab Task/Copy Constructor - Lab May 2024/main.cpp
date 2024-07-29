#include <iostream>
using namespace std;

class abc{
    int x;
    int y;
    public:
    abc(int x){
        this->x = x;
    }   
    void display(){
        cout<<&x<<endl;
        cout<<&this->x<<endl;
        cout<<this<<endl;
        // cout<<&y<<endl;
        // cout<<&this->y<<endl;
        // cout<<this<<endl;
    }
    void set(abc *obj){
        this->y = y;
        this->x = x;
        cout<<"address of obj is: "<<&obj<<endl;
    }
    void check(){
        set(this);
        cout<<"value of this : "<< this <<endl;
            cout<<"value of x : "<< x <<endl << "address of x : "<<&x<<endl;
            cout<<"value of y : "<< y <<endl << "address of y : "<<&y<<endl;
    }
};

int main()
{
    abc a(10);
    a.set(&a);
    a.check();
    // a.display();
    return 0;
}