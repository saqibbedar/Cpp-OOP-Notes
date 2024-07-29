#include <iostream>
using namespace std;

// Rectangle class
class Rectangle
{
public:
    int length;
    int breath;

    int area()
    {
        return length * breath;
    }

    int perimeter()
    {
        return 2 * (length + breath);
    }
};

int main()
{
    Rectangle r1;
    Rectangle *ptr;

    ptr = &r1;

    cout << "Enter length: ";
    cin >> ptr->length; // getting data using arrow (dereference) operator
    cout << "Enter breath: ";
    cin >> ptr->breath;

    cout << "Total area is: " << ptr->area() << endl; // printing the output

    Rectangle *ptr2 = new Rectangle();

    delete ptr2;
    return 0;
}