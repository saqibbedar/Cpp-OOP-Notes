// Q.2.a When main1 is executed, the code works. What is the output?

// file Student.h
#include <string>
#include <iostream>
using namespace std;

class Student {
    int id;
    string name;

public:
    Student(int x);
    Student();
    int getId();
    ~Student();
};

Student::Student(int x) : id(x) {
    cout << "Constructor with id = " << id << endl;
}

Student::Student() {
    cout << "Destructor with id = " << id << endl;
}

int Student::getId() {
    return id;
}

int main() {
    Student s1(8);
    const Student s2 = Student(6);
    Student* ps3 = new Student(4);
    Student s4(2);
    delete ps3;
    return 0;
}

/*
output:
    Constructor with id = 8
    Constructor with id = 6
    Constructor with id = 4
    Constructor with id = 2
    Destructor with id = 4
    Destructor with id = 2
    Destructor with id = 6
    Destructor with id = 8

*/
