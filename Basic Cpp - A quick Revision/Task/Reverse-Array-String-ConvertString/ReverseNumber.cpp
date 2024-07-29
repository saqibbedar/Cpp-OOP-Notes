#include <iostream>
#include <string>
using namespace std;


int revNum(int n){

    while(n != 0){
        int r = n%10;
        cout<<r;
        n/=10;
    }

}

int main()
{
    int num = 321;
    revNum(num);

    return 0;
}