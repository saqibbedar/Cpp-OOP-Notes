#include <iostream>
using namespace std;

int main()
{
    int x = 010;
    int y = 0x10;
    cout<<x<<"\t"<<y<<endl; // 8    16

    int a = 17;
    int b = 25;

    // cout<<a &b;
    cout<<a/b;
    return 0;
}