#include "Rectangle.hpp"

void Rectangle::set(int l, int b)
{
    length = l;
    breadth = b;
}

Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

bool Rectangle::checkArea(int l, int b)
{
    if (l < 0 || b < 0)
    {
        cerr << "Length and Breadth cannot be negative." << endl;
        Rectangle::set(1, 1);
        return false; // Indicate failure
    }
    Rectangle::set(l, b);
    return true; // Indicate success
}
