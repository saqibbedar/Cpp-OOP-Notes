#include <iostream>
using namespace std;

// :: scope resolution operator is used for accessing the global variables and used in class to access member variables and functions.

const int a = 10;
// Uninitialized variables globally would return 0 and pointer will return null
int b;
int *ptr;

int main()
{
    int a = 20;
    a= -a; 
    cout<<a<<endl; // -20

    cout<<::a<<endl; // :: resolution operator pointing to global variable so output is 10;
    
    {int a = 36;} // new declaration and this a's scope is limited to the parenthesis
    cout<<a<<endl; // -20

    {a = 36;} // accessing member variable of main() so point to the declared variable
    cout<<a<<endl; // 36

    cout<<::b<<endl; // accessing global var so output is 0

    int x;
    cout<<x<<endl; // print garbage value because initialized with in main but not assigned with any value.

    cout<<::ptr<<endl;
    // cout<<*ptr<<endl; // will throw error
    return 0;
}

/*

Unary operators: The term "unary" comes from the Latin word "unus", which means "one". Unary operators are operators that operate on only one operand. They are used to perform various operations such as incrementing/decrementing a value, negating an expression, or inverting the value of a boolean.

++, --, +, -, !, &, *, ~, sizeof, new, delete, typeid, throw



Binary operators: These operators require two operands to perform their operations. 

Arithmetic Operators: + (addition), - (subtraction), * (multiplication), / (division), % (modulus)

Assignment Operators: = (simple assignment), += (add and assign), -= (subtract and assign), *= (multiply and assign), /= (divide and assign), %= (modulus and assign)

Comparison Operators: == (equal to), != (not equal to), > (greater than), < (less than), >= (greater than or equal to), <= (less than or equal to)

Logical Operators: && (logical AND), || (logical OR)

Bitwise Operators: & (bitwise AND), | (bitwise OR), ^ (bitwise XOR), << (left shift), >> (right shift) 



Ternary operators: These operators require three operands.

?:

*/