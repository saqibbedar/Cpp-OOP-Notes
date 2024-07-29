#include <iostream>
using namespace std;
#define breakLine '\n' // will not occupy any memory and has no type 
#define brk endl
#define tab '\t'

const char en = '\n';

int main()
{
    cout<<"hello, world"<<breakLine;
    cout<<"wow it works"<<breakLine;
    cout<<"Hello,"<<tab<<tab<<"world"<<breakLine;

    cout<<"Break line "<<::en;
    cout<<"wow line got broken"<<::en;

    cout<<"testing flushing"<<breakLine<<"Wow it worked"<<breakLine;
    cout<<"hello, "<<brk<<"world";
    return 0;
}

// #define and const are two different ways to define constants in C++.

// #define: #define is a preprocessor directive, which means it's handled before the actual compilation of the code. When you write #define breakLine '\n', the preprocessor will replace every occurrence of breakLine in your code with '\n' before the code is compiled. It doesn't have a type, and it doesn't occupy any memory