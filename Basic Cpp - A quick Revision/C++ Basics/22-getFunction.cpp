#include <iostream>
using namespace std;

int main()
{
    char c;
    cin.get(c);
    cout<<"c = | "<<c<<" | "<<endl;    
        while(cin.get(c) && c!='\n'){
            cout<<"c = | "<<c<<" | "<<endl; 
        }
    return 0;
}