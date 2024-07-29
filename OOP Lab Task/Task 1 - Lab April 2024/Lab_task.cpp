#include <iostream>
#include <string>
using namespace std;

class MyClass{
    string str;
    public:
        MyClass ftn1(){
            cout<<"ftn1 : "<<endl;
            
        }
        void set(string s){
            str = s;
        }
        void ftn2(MyClass &obj){
            obj.str = str;
        }
        MyClass f3(){
            MyClass obj;
            obj.str = str;
            return obj;
        }
        
};

int main()
{
    MyClass obj;
    return 0;
}