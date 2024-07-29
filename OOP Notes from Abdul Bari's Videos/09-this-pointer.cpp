#include <iostream>
using namespace std;

class Rectangle{
    int length, breadth;

    public:
    Rectangle(int length, int breadth){
        this->length = length;
        this->breadth = breadth;
        // here this->length and breadth refers to the private members of this class and we are pointing to them and assigning them values with their same name but by using this-pointer we are preventing from name ambiguity.
    }
    int area(){
        return length * breadth;
    }

    void display();
};

void Rectangle::display(){
    cout<<"Area is: "<<area();
}

int main()
{
    Rectangle r(10, 5);
    r.display(); // 50
    
    return 0;
}