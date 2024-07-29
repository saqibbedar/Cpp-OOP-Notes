#include <iostream>
using namespace std;

struct Student {
    char name[50];
    char regNo[15];
    int marks = 0;
};

void data(Student &st){
    cout<<"\nEnter reg.no: ";
    cin>>st.regNo;
    cout<<"Enter Name: ";
    cin>>st.name;
    cout<<"Enter marks: ";
    cin>>st.marks;
}

void readData(Student* st, int size){
    for(int i=0; i<size; i++){
        data(st[i]);
    }
}

void display(Student* st, int size){
    for(int i=0; i<size; i++){
        cout<<"\nStudent reg.no: "<<st->regNo<<endl;
        cout<<"Student name: "<<st->name<<endl; 
        cout<<"Student marks: "<<st->marks<<endl;
    }
}

int main()
{
    int size;
    cout<<"Enter the size of Students: ";
    cin>>size;

    Student* st = new Student[size]; 
    readData(st, size); 
    display(st, size); 

    delete[] st;
    return 0;
}