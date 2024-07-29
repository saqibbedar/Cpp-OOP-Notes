// Assume that we have all the functions in our class, we just write two functions to get know about scope resolution operator

#include <iostream>
using namespace std;

// There are two ways to write function in the class, first one is to write functions and body inside the class and second one is to write just prototype in class body and then define body outside the class using scope resolution operator

class Rectangle{
    int length, breadth;

    public:
    // suppose we have all the functions, just writing the below functions to test the scope resolution operator
    int area(){return length * breadth;}
    int perimeter(); // we have not defined the body of perimeter function, lets see how we will access it outside the class
};

int Rectangle::perimeter(){
    return 2 * (length + breadth);
}

// what is difference b/w these two?
// Main difference is b/w them is created during the compile time, the machine code of inline function (functions that are defined with-in the class) is executed as line by line after main() in code section but when non-inline function will be in stack section and there would be a call made to that function, so it means machine code for non-inline function would be separate and there would a call made to that function

// so, inline function, is not a function now because its a part of the main now and can be accessed at anytime in main();

int main()
{
    return 0;
}