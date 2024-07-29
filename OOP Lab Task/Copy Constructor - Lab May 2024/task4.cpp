// Friend Functions: A friend function is a function that can access the private and protected members of a class

#include <iostream>
using namespace std;

class a{
    int x, y;
    public:
    a():x(10),y(20){}
    friend void display(a &);
};

void display(a &obj){
    cout<<"value of x: "<<obj.x<<endl;
    cout<<"value of y: "<<obj.y<<endl;
}

int main()
{
    a obj;
    display(obj);   
    return 0;
}
