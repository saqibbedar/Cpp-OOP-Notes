#include <iostream>
using namespace std;

// This is how a class is written, all the headers/prototypes are defined in class and their body is defined outside the class using scope resolution operator (::)

class Rectangle{

    private:
    int length;
    int breadth;

    public:
    // constructors
    Rectangle();
    Rectangle(int l, int b);
    Rectangle(Rectangle &rect);

    // Accessors (getters)
    int getLength(){return length;} // inline function
    int getBreadth(){return breadth;} // inline function

    // Mutators (setters)
    void setLength(int l);
    void setBreadth(int b);

    // Facilitators (actual functions)
    int area();
    int perimeter();

    // inspectors (inqui)
    bool isSquare();

    // destructor
    ~Rectangle(); // deallocation of object
};

int main()
{
    Rectangle r1(5, 5);
    cout<<"Area: "<<r1.area()<<endl;
    if(r1.isSquare()) cout<<"Square"<<endl;
    else cout<<"Not square"<<endl;  

    return 0;
}

Rectangle::Rectangle(){
    length = 1;
    breadth = 1;
}
Rectangle::Rectangle(int l, int b){
    length = l;
    breadth = b;
}
Rectangle::Rectangle(Rectangle &r){
    length = r.length;
    breadth = r.breadth;
}

void Rectangle::setLength(int l){
    length = l;
}

void Rectangle::setBreadth(int b){
    breadth = b;
}

int Rectangle::area(){
    return length*breadth;
}

int Rectangle::perimeter(){
    return 2*(length+breadth);
}

bool Rectangle::isSquare(){
    return length == breadth;
}

Rectangle::~Rectangle(){
    cout<<"Rectangle destroyed"<<endl;
}
