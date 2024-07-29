#include <iostream>
#include <string>
using namespace std;

class myString
{
    string str;
public:
    myString(){
        str = "Null";
    }
    myString(string str){
        this->str = str;
    }
    string concat(string str){
        return (this->str + str);
    }   
};

int main()
{
    myString hello = "Hello, ";
    string myStr = "world";

    string concatStr = hello.concat(myStr);
    cout<<concatStr<<endl;

    return 0;
}