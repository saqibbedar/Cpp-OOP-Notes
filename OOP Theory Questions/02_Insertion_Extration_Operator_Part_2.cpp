#include <iostream>
#include <string>
using namespace std;

class MyClass {
public:
    string msg = "Hello, world";
    ostream& operator<<(ostream& os); // This is incorrect
};
ostream& MyClass::operator<<(ostream& os){
    os<<msg<<endl;
    return os;
}

int main()
{
    MyClass m;
    m<<cout; // while m << cout; runs without error, but it is unconventional and not how the << operator is intended to be used.

    return 0;
}