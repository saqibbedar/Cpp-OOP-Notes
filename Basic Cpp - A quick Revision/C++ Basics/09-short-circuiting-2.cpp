// || or operator: if left side is true then right side is not evaluated

#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 10;
    // if(a != 0 || b/a < 1)
    //     cout<<"Hello, world"<<endl;
    // cout<<"done"<<endl;
    // above program will throw runtime error, because both left side is not true so right one is also evaluated and in next statement division by zero is not possible.

    if(a == 0 || b/a < 1)
        cout<<"Amazing it works  now, wow!!!"<<endl;
    cout<<"done"<<endl;

    return 0;
}