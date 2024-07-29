// write a class for student with 
/*
1. Roll Number
2. Name
3. Marks in 3 subjects
4. Functions for
   - Total marks
   - Grade
And required methods(accessors, mutators, inspectors, )
*/

#include <iostream>
using namespace std;

class Student{
    int rollNum;
    char name[45];
    int marks[3];

    public:
    Student(int rl = 0, char *name = '\0', int *marks = 0); // parameterized constructor

    void readRN();
    void readName();
    void readMarks();
    int totalMarks(){return marks[0]+marks[1]+marks[2];} //inline
    int grade();
    void displayMarks(int *marks);
    void display();
    ~Student(); // destructor
};

int main()
{
    Student s(0, '\0', 0);
    s.readRN();
    s.readName();
    s.readMarks();
    s.display();
    return 0;
}

Student::Student(int rl = 0, char *name = "\0", int *marks = 0){
    this->rollNum = rl;
    this->name[45] = *name;
    this->marks[3] = *marks;
}

void Student::readRN(){
    cout<<"What's roll number: ";
    cin>>rollNum;
}

void Student::readName(){
    cout<<"What's name: ";
    cin.getline(name, 45);
}

void Student::readMarks(){
    for(int i=0;i<3; i++){ 
        cout<<"Enter marks of your subject ["<<i+1<<"]"<< " at index " <<"["<< i <<"] : ";
        cin>>marks[i];
    }
}

void Student::displayMarks(int *marks){
    for(int i=0;i<3; i++){
        cout<<"Your marks in subject ["<<i+1<<"] are : "<<marks[i];
    }
}

void Student::display(){
    cout<<"Name :"<<name<<endl; 
    cout<<"Roll Number: "<<rollNum<<endl;
    displayMarks(marks);    
};

Student::~Student(){
    cout<<"Object deallocated successfully!"<<endl;
}