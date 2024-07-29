#include "student.h"

// calculate grade
char Student::calcGrade() const{
    int total_marks = 0;
    for(int i=0; i<total_courses; i++){
        total_marks += marks[i];
    }
    double avg = static_cast<double>(total_marks) / total_courses;
    if(avg >= 80){
        return 'A';
    }
    else if(avg >= 70){
        return 'B';
    }
    else if(avg >= 60){
        return 'C';
    }
    else if(avg >= 50){
        return 'D';
    }
    else{
        return 'F';
    }
}

// Default constructor
Student::Student() : Person(), semester(0), total_courses(0), subjects(nullptr), marks(nullptr){};
// Parameterized constructor
Student::Student(
    const string& name, const string& cnic, const string& email, const string& contact_no, int code, const Date &dob, // person parameters
    int sem, int courses, string *sub, int *m // student parameters
    ) : 
    Person(name, cnic, email, contact_no, code, dob),
    semester(sem),
    total_courses(courses),
    subjects(new string[courses]),
    marks(new int[courses])
{
    for(int i=0; i<total_courses; i++){
        subjects[i] = sub[i];
        marks[i] = m[i];
    }
}
// Copy constructor
Student::Student(const Student &other) : 
    Person(other), 
    semester(other.semester), 
    total_courses(other.total_courses),
    subjects(new string[other.total_courses]),
    marks(new int[other.total_courses])
{
    for (int i = 0; i < total_courses; i++)
    {
        subjects[i] = other.subjects[i];
        marks[i] = other.marks[i];
    }
}
// Destructor
Student::~Student()
{
    delete[] subjects;
    delete[] marks;
} 

// Setters
void Student::setSemester(int s)
{   
    while(true){
        if(s > 0){
            cout<<"Error: Invalid semester value, please enter again: "<<endl;
            cin>>s;
            if(s>1){
                break;                     
            }
        }
    }
    semester = s;
};
void Student::setTotalCourses(int c)
{
    while(true){
        if(c > 0){
            cout<<"Error: Invalid total no. of courses, please enter again: "<<endl;
            cin>>c;
            if(c>1){
                break;                     
            }
        }
    }
    total_courses = c;
};
void Student::setSubjects(const string& str, int index)
{
    
    if(index >= 0 && index < total_courses){
        subjects[index] = str;
    }
};
void Student::setMarks(int m, int index)
{
    if (index >= 0 && index < total_courses)
    {
        marks[index] = m;
    }
}
// Getters
int Student::getSemester() const
{
    return semester;
};
int Student::getTotalCourses() const
{
    return total_courses;
};
string *Student::getSubjects() const
{
    return subjects;
};
int *Student::getMarks() const
{
    return marks;
};

// Input output functions
void Student::print() const{
    cout<<"\n\n***** Student Information *****\n"<<endl;
    cout<<*this;
}
void Student::read(){
    cout<<"\n\n***** Enter Student Information *****\n"<<endl;
    cin>>*this;
}

// Input output functions
ostream &operator<<(ostream &out, const Student &std){
    out<<(const Person&)std<<endl
    <<"Semester: "<<std.semester<<endl
    <<"Total Courses: "<<std.total_courses<<endl
    <<"Subjects: [";
    for(int i=0; i<std.total_courses; i++){
        if(i == std.total_courses -1){
            out<<std.subjects[i];
        }else{
            out<<std.subjects[i]<<", ";
        }
    }
    out<<"]"<<endl
    <<"Marks: [";
    for(int i=0; i<std.total_courses; i++){
        if(i == std.total_courses -1){
            out<<std.marks[i];
        }else{
            out<<std.marks[i]<<", ";
        }
    }
    out<<"]";

    return out;
}

istream &operator>>(istream &in, Student &std){

    in>>(Person&)std;
    cout<<"Enter semester: ";
    in>>std.semester;
    cout<<"Enter No. of Courses: ";
    in>>std.total_courses;
    cin.ignore(); 

    // Allocate memory for subjects and marks
    std.subjects = new string[std.total_courses];
    std.marks = new int[std.total_courses];

    cout<<"Enter Subjects: "<<endl;
    for(int i=0; i<std.total_courses; i++){
        in>>std.subjects[i];
    }

    cout << "Enter Marks:" << endl;
    int m;
    for (int i = 0; i < std.total_courses; i++) {
        do {
            in >> m;
            if (m >= 1 && m <= 100) {
                std.marks[i] = m;
                break;
            } else {
                cout << "Error: marks out of range (1-100): ";
            }
        } while (true);
    }

    return in;
}

ostream& print_std(ostream& out, const Student& std){
    out
    <<"Semester: "<<std.semester<<endl
    <<"Total Courses: "<<std.total_courses<<endl
    <<"Subjects: [";
    for(int i=0; i<std.total_courses; i++){
        if(i == std.total_courses -1){
            out<<std.subjects[i];
        }else{
            out<<std.subjects[i]<<", ";
        }
    }
    out<<"]"<<endl
    <<"Marks: [";
    for(int i=0; i<std.total_courses; i++){
        if(i == std.total_courses -1){
            out<<std.marks[i];
        }else{
            out<<std.marks[i]<<", ";
        }
    }
    out<<"]";

    return out;
}
istream& read_std(istream& in, Student& std){
    cout<<"Enter semester: ";
    in>>std.semester;
    cout<<"Enter No. of Courses: ";
    in>>std.total_courses;
    cin.ignore(); 

    // Allocate memory for subjects and marks
    std.subjects = new string[std.total_courses];
    std.marks = new int[std.total_courses];

    cout<<"Enter Subjects: "<<endl;
    for(int i=0; i<std.total_courses; i++){
        in>>std.subjects[i];
    }
    cout << "Enter Marks:" << endl;
    int m;
    for (int i = 0; i < std.total_courses; i++) {
        do {
            in >> m;
            if (m >= 1 && m <= 100) {
                std.marks[i] = m;
                break;
            } else {
                cout << "Error: marks out of range (1-100): ";
            }
        } while (true);
    }
    return in;
}

// isSuccessful?
bool Student::isSuccessful() const{ 
    return ( calcGrade() <= 'C');
}
