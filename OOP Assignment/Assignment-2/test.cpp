#include <iostream>
using namespace std;

const int MaxYear = 2008;
const int MinYear = 1950;

struct Date
{
    int day;
    int month;
    int year;
};

struct Student{
    char regNo[10]; 
    char name[45];
    Date dob;
    int marks[5];

    // read marks
    void readMarks(){
        for(int i= 1; i<=5; i++){
            cout<<"What's marks of your subject "<<i<<" : ";
            cin>>marks[i];
        }
    }

    // display marks
    void displayMarks(){
        for(int i= 1; i<=5; i++){
            cout<<"Subject "<<i<<" : "<<marks[i]<<endl;
        }
    }
};

void handle_marks(Student *st, int size){
    for(int i=0, j=1; i<size; i++, j++){
        cout<<"What's marks of your subject "<<j<<" : ";
        cin>>st[i].marks[j];
    }
}


int main()
{
    Student st[5];
    handle_marks(st, 5);

    return 0;
}