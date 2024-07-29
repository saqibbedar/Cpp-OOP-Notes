#include <iostream>
#include <string>
using namespace std;

struct dob{
    int day;
    int month;
    int year;
};

struct Student{
    char name[45] = "\0";
    int rollNo = 31;
    dob d;
};

int main()
{
    Student p;
    cin>>p.name;
    cin>>p.rollNo;

    cout<<p.name<<endl;
    cout<<p.rollNo<<endl;

    return 0;
}