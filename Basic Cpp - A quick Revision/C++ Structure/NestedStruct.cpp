#include <iostream>
using namespace std;

struct Person
{
    char name[45];
    Person(){
        name[45] = '\0';
    }
    struct Date
    {
        int day;
        int month;
        int year;
        Date(){
            day = 0;
            month = 0;
            year = 0;
        }
    } dob;
};


int main()
{
    Person person;
    cout<<"Enter your name: ";
    cin.getline(person.name, 45);
    cout<<"Enter birthday: ";
    cin>>person.dob.day;
    cout<<"Enter birth year: ";
    cin>>person.dob.month;
    cout<<"Enter birth year: ";
    cin>>person.dob.year;

    cout<<"\nName: "<<person.name<<endl;
    cout<<"DOB: "<<person.dob.day<<"/"<<person.dob.month<<"/"<<person.dob.year<<endl;

    return 0;
}