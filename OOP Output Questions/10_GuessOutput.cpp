/*
    The following does not work. Fix all errors (without removing or adding any function or commenting the code). After fixing the code, what will be the output of the code when main() is executed.
*/

#include <iostream>
#include <string>
using namespace std;

// Code with error

// class CSDep {
//     const int no_of_labs = 0; 
//     const string OOP_teacher = "Khoofnaak";
// public:
//     CSDep(){}
//     CSDep (const string& n){
//         no_of_labs = 4;
//         OOP_teacher = n;
//     }
//     int get_no_of_labs(){
//         return no_of_labs;
//     }
//     string get_OOP_teacher(){
//         return OOP_teacher;
//     }

//     void print(const CSDep& ){}
// };

// int main(){
//     CSDep cs1, cs2("MAM");
//     cs1.print();
//     cs2.print();

//     return 0;
// }

// friend void print(const CSDep& ){
//     cout<<no_of_labs<<endl;
//     cout<<OOP_teacher<<endl;
// }  


// solution

class CSDep {
    const int no_of_labs;
    const string OOP_teacher;
public:
    // Default constructor with member initializer list
    CSDep() : no_of_labs(0), OOP_teacher("Khoofnaak") {}

    // Parameterized constructor with member initializer list
    CSDep(const string& n) : no_of_labs(4), OOP_teacher(n) {}

    int get_no_of_labs() const {
        return no_of_labs;
    }

    string get_OOP_teacher() const {
        return OOP_teacher;
    }

    // Member function to print
    void print() const {
        cout << "Number of Labs: " << no_of_labs << endl;
        cout << "OOP Teacher: " << OOP_teacher << endl;
    }
};

int main() {
    CSDep cs1, cs2("MAM");
    cs1.print();
    cs2.print();

    return 0;
}

/*
output:
    0
    Khoofnaak
    4
    MAM
*/