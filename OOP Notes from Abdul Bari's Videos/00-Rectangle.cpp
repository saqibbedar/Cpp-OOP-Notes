#include <iostream>
using namespace std;

// Rectangle class
class Rectangle
{
    // to access the members outside the class, we are suppose to make them public first
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
    // classes are used to define the user defined dataType
    Rectangle r1; // r1 is a variable of Rectangle dataType (User defined dataType) and these variables are also called objects or instance of a class

    cout << "Enter length: ";
    cin >> r1.length; // getting data using dot (.) method/operator
    cout << "Enter breath: ";
    cin >> r1.breath;

    cout << "Total area is: " << r1.area() << endl; // printing the output

    Rectangle r2;

    cout << "Enter length: ";
    cin >> r2.length; // getting data using dot (.) method/operator
    cout << "Enter breath: ";
    cin >> r2.breath;

    cout << "Total area is: " << r2.area() << endl; // printing the output

    return 0;
}