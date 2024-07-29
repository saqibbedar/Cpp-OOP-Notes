// The following code segment do not work. Fix them without removing or commenting the code. After you fix, what is the output.

#include <iostream>
#include <cstring>
using namespace std;

// code segment with issue

// class Student {
//     int id;
//     char name[30];

// public:
//     Student(int, char*);
//     ~Student();
//     int getid();
// };

// Student::Student(int x, char* nm) {
//     id = x;
//     strcpy(name, nm);
//     cout << "Constructor with id = " << id << endl;
// }

// Student::~Student() {
//     cout << "Destructor with id = " << id << endl;
// }

// int Student::getid() {
//     return id;
// }

// int main() {
//     Student s1(7, "XXX");
//     const Student s2 = s1;
//     Student s4(4, "ZZZ");
//     cout << s4.getid() << endl;
//     cout << s2.getid() << endl;
    
//     return 0;
// }


// correct version of the code:

class Student {
    int id;
    char name[30];

public:

    Student(int, const char*); // it is better to make char* const to avoid ISO c++ warnings. ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]

    ~Student();
    int getid() const; // Function should be const to be called on a const object
};

Student::Student(int x, const char* nm) {
    id = x;
    strcpy(name, nm);
    cout << "Constructor with id = " << id << endl;
}

Student::~Student() {
    cout << "Destructor with id = " << id << endl;
}

int Student::getid() const {
    return id;
}

int main() {
    Student s1(7, "XXX");
    const Student s2 = s1;
    Student s4(4, "ZZZ");
    cout << s4.getid() << endl;
    cout << s2.getid() << endl;
    return 0;
}

/*
output:
    Constructor with id = 7
    Constructor with id = 4
    4
    7
    Destructor with id = 4
    Destructor with id = 7
*/