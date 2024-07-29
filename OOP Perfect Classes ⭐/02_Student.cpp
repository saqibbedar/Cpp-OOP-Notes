/*

Create an abstract class Student having members id (string), name (string), department (string), marksObtained. Provide parameterized constructor with default values, and overloaded << operator for this class. Also write print member functions for the class that calls overloaded << operator for the class to print it. Derive two classes from Student class, to represent graduate and undergraduate students. Graduate students have some more data members like thesis title (string), Faculty advisor (string), and area of research (string). Undergrad students have additional data members like project title (string), and project supervisor (string). Provide default argument constructors, and overload << operator for both derived classes. Write print member functions for both classes, which call overloaded << operators for the respective classes to print them.

Provide a function Calc_grade that returns the grade of the student. For undergrad students, the grading scheme is same as in QAU. For grad students 'A' grade starts from 85%, 'B' starts from 75%, 'C' starts from 60% and below 60% is an 'F'.

Write a main function that creates a single array of size 5 and store addresses of both grad and undergrad students in this array. Print all data along with grades of all students in the array

*/
#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string id, name, department;
    int ObtainedMarks;

public:
    // Parametrized constructor with default values
    Student(
        const string& id = "111-444-999", 
        const string& name = "Saqib Bedar", 
        const string& department = "Computer Science", 
        int ob_marks = 90
        ) : 
        id(id), 
        name(name), 
        department(department), 
        ObtainedMarks(ob_marks) 
    {}
    
    // Virtual Destructor
    virtual ~Student(){}

    // pure virtual function
    virtual char calc_grade() const = 0;

    // print functions
    friend ostream &operator<<(ostream &out, const Student &st)
    {
        out << "ID: " << st.id << endl
            << "Name: " << st.name << endl
            << "Department: " << st.department << endl
            << "Obtained Marks: " << st.ObtainedMarks;
        return out;
    }

    virtual void print() const
    {
        cout << *this << endl;
    }
};

class Graduate_Student : public Student 
{
    string thesis_title, fac_adv, research_area;
    
    public:

    // Parametrized constructor with default values
    Graduate_Student
    (
        // Student constructor parameters
        const string& id = "111-444-999", 
        const string& name = "Saqib Bedar", 
        const string& department = "Computer Science", 
        int ob_marks = 90,

        // Graduate Student parameters
        const string& thesis_title = "Developers survival in the age of AI", 
        const string& fac_adv = "Prof. David J. Malan",
        const string& research_area = "Artificial Intelligence"
    ) : 
        Student(id, name, department, ob_marks),
        thesis_title(thesis_title),
        fac_adv(fac_adv),
        research_area(research_area)
    {}

        friend ostream &operator<<(ostream &out, const Graduate_Student& g_std)
    {
        out << (const Student&)g_std<<endl
        <<"Thesis title: "<<g_std.thesis_title<<endl
        <<"Faculty Advisor: "<<g_std.fac_adv<<endl
        <<"Area of Research: "<<g_std.research_area;
        return out;
    }

    void print () const override 
    {
        cout << *this << endl;
    }

    char calc_grade() const override
    {
        if(ObtainedMarks >= 85) return 'A';
        if(ObtainedMarks >= 75) return 'B';
        if(ObtainedMarks >= 60) return 'A';
        return 'F';
    };

};

class Undergraduate_Student : public Student
{   
    string project_title, project_supervisor;

    public:
    Undergraduate_Student(
        // Student constructor parameters
        const string& id = "111-444-999", 
        const string& name = "Saqib Bedar", 
        const string& department = "Computer Science", 
        int ob_marks = 90,
        // Undergraduate Constructor parameters
        const string& project_title = "Social Network",
        const string& project_supervisor = "Prof. Emmanuel"
        ) : 
        Student(id, name, department, ob_marks),
        project_title(project_title),
        project_supervisor(project_supervisor)
    {}

    friend ostream& operator<<(ostream& out, const Undergraduate_Student& u_std){
        out<<(const Student&)u_std<<endl
        <<"Project Title: "<<u_std.project_title<<endl
        <<"Project Supervisor: "<<u_std.project_supervisor;
        return out;
    }

    void print() const override{
        cout<<*this<<endl;
    }

    char calc_grade() const override{
        if(ObtainedMarks >= 80) return 'A';
        if(ObtainedMarks >= 70) return 'B';
        if(ObtainedMarks >= 60) return 'c';
        if(ObtainedMarks >= 50) return 'D';
        return 'F';
    }
};

int main()
{
    Student* students[5];

    students[0] = new Graduate_Student(); // default data will print
    students[1] = new Undergraduate_Student(); // default data will print
    students[2] = new Graduate_Student("G2", "Charlie", "Mechanical Engineering", 92, "Robotics", "Dr. Brown", "Automation");
    students[3] = new Undergraduate_Student("U2", "David", "Civil Engineering", 82, "Sustainable Buildings", "Prof. Wilson");
    students[4] = new Graduate_Student("G3", "Eve", "Physics", 78, "Quantum Computing", "Dr. Clark", "Quantum Mechanics");

    cout<<"\n";

    for(int i=0; i<5; i++){
        students[i]->print();
        cout << "-----------------------------------" << endl;
    }

    // Deleting dynamically allocated memory
    for (int i = 0; i < 5; ++i) {
        delete students[i];
    }

    return 0;
}