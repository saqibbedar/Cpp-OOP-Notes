#pragma once

#include <iostream>
using namespace std;

class Rectangle
{
    int length, breadth;

public:
    Rectangle(int l, int b);
    void set(int l, int b);

    int getLength() { return length; }
    int getBreadth() { return breadth; }

    double area() { return length * breadth; }

    bool checkArea(int l, int b);

    ~Rectangle() {}
};