/*
Constructor: A constructor is a function, which has same name as of class and it has no return type but exactly same of a class.
Example: class Student{
    int rollNumber;
    public:
        Student(){ // this is a constructor
            rollNumber = 0; // giving default value to prevent a garbage value
        }
};

There are four types of constructors as follows:

    1. Default constructors: provided by compiler that is created during compilation time and it is assign some garbage values to member variables, it is also called as built-in constructor.

    ! these all three are user defined constructors: 
    2. Non-parameterized constructor: a user defined constructor with no parameters

    Example: Rectangle(){
        length = 0;
        breadth = 0;
    }

    3. Parameterized constructor: a user defined constructor with parameters (for parameterized constructor, we have to create an object and pass the parameters)

    Example: Rectangle(int l, int b){
        setLength(l);
        setBreadth(b);
    }

    3. copy constructor: a user defined constructor that copies a given constructor, we pass a constructor as a parameter to constructor that is called a copy constructor.

    Example: Rectangle(){

    }

*/

#include <iostream>
using namespace std;

class Rectangle {
    public:
    int length, breadth;

    //! constructors

    // non-parameterized 
    // Rectangle(){
    //     this->length = 0;
    //     this->breadth = 0;
    // } // there is no need of this constructor because we are using parameterized constructor and we are assigning the values to that constructor so it will work for us, so there is no need to write this constructor

    // parameterized
    Rectangle(int l = 0, int b = 0){
        setLength(l);
        setBreadth(b);
    } 

    // copy constructor
    Rectangle(Rectangle &rect){
        length = rect.length;
        breadth = rect.breadth;
    }; 
    
    //! Mutators
    void setLength(int l){
        if(l < 0){
            cout<<"Length can't be -ve: "<<l <<endl;
            length = 1;
        } else length = l;    
    }
    void setBreadth(int b){
        if(b < 0) {
            cout<<"breadth can't be -ve: "<<b<<endl; 
            breadth=1;
        } else breadth = b;
    }

    //! Accessors
    int getLength(){
        return length;
    }
    int getBreadth(){
        return breadth;
    }

    //! Actual functions
    int area(){
        return length * breadth;
    }
    int perimeter(){
        return 2 * (length + breadth);
    }

    //! inspectors

    //! destructor
};

int main(){
    Rectangle r1(10, -5);
    Rectangle r2(r1);

    // by using copy constructor
    cout<<r2.area()<<endl;

    return 0;
}
