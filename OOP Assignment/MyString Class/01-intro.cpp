#include <iostream>
using namespace std;

int main(){
    const char *p = nullptr, *q = nullptr;
    p = "Hello,";
    q = " world";

    cout<<p<<q<<endl; // Hello, world
    char a = 'a';
    int aA = 97;

    cout<<int(a)<<" " <<char(aA)<<endl; // 97 a

    return 0;
}