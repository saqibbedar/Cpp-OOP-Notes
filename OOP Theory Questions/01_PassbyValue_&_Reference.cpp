/* Question: In our popular Student class, the name of the student is stored as a C++ string. Not as a pointer and not as a reference; just a plain C++ string. Assume that the class provides a getter as:

        const string& getName() const;

i) The function could have returned a non-reference; what is the motivation in making the return type a reference? State the reason in one short sentence, no stories! and tod call of copy constructor

ii) Assume that we decided that the return type will be a reference for the reason you stated in the above part. Is it absolutely necessary to make the return type a const? Why? Why not? 

iii) c. Overloading of insertion operator ("<<") was shown to be taking an ostream reference as a parameter. Is it also okay to pass the ostream by value? Why? Why not?

Answer:
i) The function returns a reference to avoid the overhead of copying the string.

ii) Yes, it is necessary to make the return type const to prevent the caller from modifying the internal state of the Student object.

iii) No, it is not okay to pass the ostream by value because it would create an unnecessary copy, which is inefficient and can lead to incorrect behavior.

Returning by reference avoids the overhead of copying large objects.
Making the return type const prevents modification of the internal state of the object.
Passing ostream by reference avoids the inefficiency and incorrect behavior associated with copying streams.

*/

#include <iostream>
using namespace std;

void printByValue(ostream os) {
    os << "Hello, by value!" << endl; // This will not affect the original stream
}

void printByReference(ostream& os) {
    os << "Hello, by reference!" << endl; // This will write to the original stream
}

int main() {
    cout << "Original message" << endl;

    // Pass by value
    printByValue(cout); // This does not actually print to cout

    // Pass by reference
    printByReference(cout); // This prints to cout

    return 0;
}

/*
output: 
    Original message
    Hello, by reference!
*/ 
