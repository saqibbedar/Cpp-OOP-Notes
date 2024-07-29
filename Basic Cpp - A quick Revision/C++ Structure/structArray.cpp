#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Student {
    char regNum[15];
    char name[45];
    int marks[5];
    Date dob;
};

void inputDob(Student &dob){
    cout<<"Enter your birthday: ";
    cin>>dob.dob.day;
    cout<<"Enter your birth month: ";
    cin>>dob.dob.month;
    cout<<"Enter your birth year: ";
    cin>>dob.dob.year;
}

void inputMarks(Student &marks){
    string subjects[] = {"English", "OOP", "Sociology", "Physic", "Mathematics"};
    for(int i=0; i<5; i++){
        cout<<"Enter your "<<subjects[i]<<" marks: ";
        cin>>marks.marks[i];
    }
}

void data(Student &st){
    cout<<"\nEnter your Registration Number: ";
    cin>>st.regNum;
    cout<<"Enter your Name: ";
    // cin.get(st.name);
    cin>>st.name;
}

// main function to input data
void input(Student* st, int size){
    for(int i=0; i<size; i++){
        data(st[i]);
        inputMarks(st[i]);
        inputDob(st[i]);
    }
}

void displayData(Student &st){
    cout<<"\nStudent Reg.No is: "<<st.regNum<<endl;
    cout<<"Student Name: "<<st.name<<endl;
}

void displayMarks(Student &marks){
    string subjects[] = {"English", "OOP", "Sociology", "Physic", "Mathematics"};
    for(int i=0; i<5; i++){
        cout<<"Marks in "<<subjects[i]<<" are "<<marks.marks[i]<<endl;
    }
}

void displayDob(Student &dob){
        cout<<"DOB: " <<dob.dob.day<<"/"<<dob.dob.month<<"/"<<dob.dob.year<<endl;
}

// main function to display data
void output(Student* st, int size){
    for(int i=0; i<size; i++){
        displayData(st[i]);
        displayMarks(st[i]);
        displayDob(st[i]);
    }
}

int main()
{
    int size;
    cout<<"Enter size of students: ";
    cin>>size;
    Student* st = new Student[size];
    input(st, size);
    output(st, size);

    delete[] st;
    return 0;
}