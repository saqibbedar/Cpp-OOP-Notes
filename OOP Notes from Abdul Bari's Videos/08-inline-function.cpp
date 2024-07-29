#include <iostream>
using namespace std;

// If your function is defined inside the class is called inline function and if a function is defined outside the class and heading/prototype is defined inside the class is called non-inline function

class Rectangle{
    int length, breadth;

    public:
    Rectangle(int l=1, int b=1){
        length = l;
        breadth = b;
    }
    int area(){return length * breadth;} // inline funtion
    int perimeter(); // non-inline function

    inline void display(); // even we are just writing the prototype here inside the class, and this is to considered as non-inline function but it is inline function now due to keyword I have used before its data-type and now it is inline
};

int Rectangle::perimeter(){
    return 2 * (length + breadth);
}

void Rectangle::display(){
    cout<<area();
}

int main()
{
    Rectangle r1(10, 5);
    r1.display(); // 50

    return 0;
}