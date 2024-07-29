#include <iostream>
#include <string>
using namespace std;

struct Person
{
    string name;
    int age;
    Person(){
        name = "Hello world";
        age = 0;
    }
    void input(){
        cout<<"Enter your Name: ";
        cin>>name;
        cout<<"Enter your age: ";
        cin>>age;
    }
    void output(){
        cout<<"Name: "<<name;
        cout<<"age: "<<age;
    }
};


int main()
{
    Person p1;
    p1.input();
    p1.output();

    return 0;
}