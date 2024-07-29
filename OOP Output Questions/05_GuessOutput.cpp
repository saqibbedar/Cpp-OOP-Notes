// Q.2.b When main2 is executed, the code does not work. Fix it (without removing or commenting the code). After your fix, what is the output?

// file main2.cpp
// #include "Student.h" 

// this question is second part of 04_GuessOutput.cpp question, class is same but in main() values are given different and functions are called differently so it has an error and we have to find it and solve it and print the final output.

#include <iostream>
#include <string>
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
    const Student s2 = Student(4);
    Student s4(2);
    cout << s4.getId() << endl;
    cout << s2.getId() << endl; // error

    // Explanation: The code does not compile because the Student class does not mark the getId method as const. This prevents it from being called on a const object like s2.

    // solution: To fix this, we need to mark the getId method as const in the class definition. int getId() const; // Marked as const


    // After fixing output will be:

    /*
    output:
        Constructor with id = 8
        Constructor with id = 4
        Constructor with id = 2
        2
        4
        Destructor with id = 2
        Destructor with id = 4
        Destructor with id = 8
    */
    return 0;
}
