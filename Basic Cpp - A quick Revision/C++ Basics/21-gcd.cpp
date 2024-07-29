// Euclidean algorithm to find greatest common multiple (gcd)

#include <iostream>
using namespace std;

void gcd(int &num, int &denom){
    
    if(denom < 0){
        denom = -denom;
        num = -num;
    }
    int n = num < 0? -num : num;
    int d = denom;
    int r = n%d;

    while(r!=0){
        n = d;
        d = r;
        r = n&d;
    }

    num /= d;
    denom /=d;
}

int main(){
    int x = 4, y = -16;
    gcd(x, y);
    cout<<x<<"/"<<y;
    return 0;
}