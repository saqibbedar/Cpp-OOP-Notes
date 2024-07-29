#include "Rectangle.hpp"

int main()
{
    Rectangle r(0, 0);

    int length, breadth;

    cout<<"Enter length: ";
    cin>>length;
    cout<<"Enter breadth: ";
    cin>>breadth;

    r.checkArea(length, breadth);

    double totalArea = r.area();

    cout << "Length is: " << r.getLength() << endl
         << "Breadth is: " << r.getBreadth() << endl
         << "Total Area is: "<< totalArea << endl;

    return 0;
}

// run command g++ -o my_program main.cpp Rectangle.cpp
