// && operator: if left-side is false then right side in never evaluated.

#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 10;
    // if(a >= 0 && b/a < 1){
    //     cout<<"hello, world"<<endl;
    // }
    // cout<<"done"<<endl; 
    // this program will cause runtime error because left side is true so the next statement on right side would also be evaluated, hence, division by zero is not possible so it is a runtime error.

    // but if left-hand-side is false then right-hand-side is never evaluated

    if(a != 0 && b/a < 1)
        cout<<"I am an error!"<<endl;
    cout<<"done"<<endl;
    return 0;
}