#include <iostream>
using namespace std;

int main()
{
    cout<<15*3 + 11/11 + 4 *2 /2<<endl;
    // 15*3 is evaluated first because multiplication has higher precedence than addition and division. This results in 45. 11/11 is evaluated next, resulting in 1. 4*2/2 is evaluated next, resulting in 4. The addition operations are then performed, resulting in 45 + 1 + 4 = 50
    
    return 0;
}