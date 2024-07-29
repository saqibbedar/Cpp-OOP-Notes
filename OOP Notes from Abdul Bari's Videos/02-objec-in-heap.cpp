#include <iostream>
using namespace std;

// Rectangle class 
class Rectangle{
    public:

    int length;
    int breath;

    int area(){
        return length * breath;
    }

    int perimeter(){
        return 2*(length+breath);
    }
};

int main()
{
    Rectangle *ptr = new Rectangle(); // allocation: object is created in heap with no name but it is allocated and ptr is pointing to that object

    cout<<"Enter length: ";
    cin>>ptr->length; 
    cout<<"Enter breath: ";
    cin>>ptr->breath;

    cout<<"Total area is: "<<ptr->area()<<endl; 

    delete ptr; // deallocate 
    return 0;
}