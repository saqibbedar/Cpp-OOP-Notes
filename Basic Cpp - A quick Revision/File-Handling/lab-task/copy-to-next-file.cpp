#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream obj("text2.txt");
    string str, str2;
    cout<<"hhhhhhh";
    obj << str;

    obj.seekp(0);
    obj >> str2;
    cout<<str<<endl;

    // get cursor position 
    obj.tellp();
    
    return 0;
}