// write a program to find prime number

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num){

    if(num < 2) return false;

    int limit = sqrt(num);

    for(int i=2; i<limit; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int num = 231;
    if(isPrime(num)) cout<<num<<" is a Prime number";
    else cout<<num<<" is not a Prime number";

    return 0;
}