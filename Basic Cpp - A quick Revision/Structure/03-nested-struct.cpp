// Nested structure: it shows structure with-in a structure.
#include <iostream>
using namespace std;

struct Date{
    int day, month, year;
};

struct Student{
    char regNo[15], name[45];
    int marks[5];
    Date dob;
};

int main()
{
    Student s1 = {
        "037", // assign to regNo
        "John Doe", // assign to name
        {70, 80, 90, 75, 67}, // assign ot marks array
        {1, 1, 1997} // date 
    };

    cout<<"Name: "<<s1.name<<endl
    <<"Roll No: "<<s1.regNo<<endl;
    cout<<"Marks: "<<s1.marks[0]<<", "<<s1.marks[1]<<", "<<s1.marks[2]<<", "<<s1.marks[3]<<", "<<s1.marks[4]<<", "<<s1.marks[5]<<endl;
    cout<<"DOB: "<<s1.dob.day<<"/"<<s1.dob.month<<"/"<<s1.dob.year<<endl;

    return 0;
}