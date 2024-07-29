#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;

public:
    Student(const string& name) : name(name) {}

    // Returning a non-const reference
    string& getName() {
        return name;
    }
};

class Undergraduate{
    string name;
    public:
    Undergraduate(const string& name): name(name){}
    const string& getName() const{
        return name;
    }
};

int main() {
    Student student("Alice");
    Undergraduate u_student("John");

    // Getting a non-const reference
    string& name = student.getName();
    string u_name = u_student.getName();

    // testing student
    cout << "Student original name: " << name << endl; // Alice
    // Modifying the internal state
    name = "Bob";
    cout << "Modified name: " << student.getName() << endl; // bob

    // testing undergraduate student
    cout<<"Undergraduate Student original name: "<<u_name<<endl; // john
    // modifying internal state of undergraduate student
    u_name = "Jack";
    cout<<"Undergraduate student modified name: "<< u_student.getName() <<endl; // john

    return 0;
}
