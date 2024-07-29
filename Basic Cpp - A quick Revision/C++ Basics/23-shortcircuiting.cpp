#include <iostream>
using namespace std;

int main()
{
    int a = 0, b=10;
    // short circuiting: if left-side is false then right side is not evaluated in case of &&
    if(b != 10 && b/a < 1){
        cout<<a<<" , "<<b<<" , "<<b/a<<endl;
    }
    cout<<"done";
    
    cout<<"\n";
    // In OR || if left side is = True then right-side is not evaluated
    if(a!=0 || b/a > 1){ // runtime error
        cout<<"done"<<endl;
    }
    cout<<"none";

    if(a==0 || b/a > 1){
        cout<<"done"<<endl;
    }
    cout<<"none";
    return 0;
}