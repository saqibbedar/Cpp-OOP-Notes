// Find and explain only compile time errors in the following code.

#include <iostream>
using namespace std;

class Person{
public:
    Person(string n="", string a=""){
        name = n;
        address = a;
    }
    void set_address(string a){
        address = a;
    }
    private:
    string name;
    string address;
};

class Student : public Person{
    public:
    Student(string d) {
        dept = d;
    }
    private:
    string dept;
};

class Teacher : private Person{
    public:
    Teacher(string rank = ""){
        designation = rank;
    }
    void print_name(){
        cout<<name<<endl; // error: accessing private member
    }
    private:
    string designation;
};

int main(){
    Person p;
    Student std; // error: not passing value as constructor requires it 
    Teacher t;
    p.set_address("Person Address");
    std.set_address("Student Address");
    t.set_address("Teacher Address"); // can't access set_address as privately inherit it 

    return 0;
}
