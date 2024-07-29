// The following code segment do not work. Fix them without removing or commenting the code. After you fix, what is the output.

#include <iostream>
using namespace std;

// Code with issues: 

// class Building {
//     const int no_of_rooms;

// public:
//     Building();
//     friend void print(const Building&) const; // Error lies here
//     const int& getrooms() const;
// };

// Building::Building() : no_of_rooms(1) {
//     cout << no_of_rooms << endl;
// }

// void print(const Building& b) { 
//     cout << b.no_of_rooms << endl;
// }

// const int& Building::getrooms() const {
//     return no_of_rooms;
// }

// int main() {
//     Building r;
//     print(r);
//     return 0;
// }


// correct version of the code: 

class Building {
    const int no_of_rooms;

public:
    Building();
    // The friend function declaration should not have const at the end.
    friend void print(const Building&); // Corrected friend function declaration
    const int& getrooms() const;
};

Building::Building() : no_of_rooms(1) {
    cout << no_of_rooms << endl;
}

void print(const Building& b) {
    cout << b.no_of_rooms << endl;
}

const int& Building::getrooms() const {
    return no_of_rooms;
}

int main() {
    Building r;
    print(r);
    return 0;
}

/*
Output: 
    1
    1
 */