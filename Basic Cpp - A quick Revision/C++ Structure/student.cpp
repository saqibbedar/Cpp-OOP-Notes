#include <iostream>
#include <string>
using namespace std;

struct Student{
    char regNo[15];
    char name[50];
    int marks[5];
};

void input(Student &data){
    cout<<"\nEnter reg.no: ";
    cin>>data.regNo;
    cout<<"Enter your name: ";
    cin>>data.name;
    string subjects[5] = {"English", "OOP", "Physics", "Mathematics", "Social Science"};
    for(int i=0; i<5; i++){
        cout<<"Enter "<<subjects[i]<<" Marks: ";
        cin>>data.marks[i];
    }
}

void output(Student data){
    cout<<"\nStudent reg.no: "<<data.regNo<<endl;
    cout<<"Student name: "<<data.name<<endl;
    string subjects[5] = {"English", "OOP", "Physics", "Mathematics", "Social Science"};
    for(int i=0; i<5; i++){
        cout<<"Marks in "<<subjects[i]<<" "<<data.marks[i]<<endl;
    }
}

int main()
{
    Student st, st1[5];
    input(st);
    output(st);
    
    return 0;
}