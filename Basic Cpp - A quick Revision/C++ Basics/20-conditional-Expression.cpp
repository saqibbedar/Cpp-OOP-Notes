#include <iostream>
using namespace std;

// conditional Expression are also called as ternary operator

int main()
{
    int marks = 45;
    cout<<(marks >= 50)? "Pass\n" : "Fail\n"; // 0 for false and 1 for true
    cout<<(marks >= 50? "Pass\n" : "Fail\n"); // fail 

    marks = 100;
    cout<<(marks >= 50)? "Pass\n" : "Fail\n";
    cout<<(marks >= 50? "Pass\n" : "Fail\n");

    return 0;
}