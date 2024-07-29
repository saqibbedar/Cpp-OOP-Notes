/*
    Define an abstract base class called UniversityMember that has attributes name, and department, which are strings. Two classes are derived from University Member Student and Teacher. Each student has attributes such as how many courses he/she is enrolled in, and one or more dynamic array(s) used to store the names of the courses, and the corresponding GPAS (0-4) he/she got in those courses. Teachers have attributes such as designation, no of publications, the number of courses they're offering and number of students they supervised

    a. Write appropriate parameterized constructors with default values for each class

    b. Overload << and >> operators for all classes.

    c. Write a Boolean valued overridden function IsSuccessful() for each class which returns true for students if they have their CGPA > 3.0, and for teachers if they have more than 20 publications.

    d. Create a class TeachingAsst which is derived from Teacher and Student. It has a single string attribute supervisor. Create a parameterized constructors with default values. Make sure that TeachingAsst inherits only one copy of University Member. Provide IsSuccessful() for TeachingAsst too which retuns true if TA has CGPA 3.0 and has assisted more than 3 courses.

    e. Finally, test the classes in a C++ program. In the test program, you should dynamically allocate some students, teachers and TAs using array of pointers to University Member, input and print their corresponding attributes and then release the dynamically allocated objects in the end.

*/

#include <iostream>
#include <string>
using namespace std;

class UniversityMember {
protected:
    string name;
    string department;

public:
    UniversityMember(const string& name = "", const string& department = "") : 
    name(name), department(department) {}

    virtual ~UniversityMember() {}

    friend istream& operator>>(istream& in, UniversityMember& member) {
        getline(in, member.name);
        getline(in, member.department);
        return in;
    }

    friend ostream& operator<<(ostream& out, const UniversityMember& member) {
        out << "Name: " << member.name << "\nDepartment: " << member.department;
        return out;
    }

    virtual bool IsSuccessful() const = 0; // Pure virtual function
    virtual void read() = 0;               // Pure virtual function for reading data
    virtual void write() const = 0;        // Pure virtual function for writing data
};


class Student : virtual public UniversityMember {
protected:
    int num_courses;
    string* course_names;
    float* gpas;

public:
    Student(const string& name = "", const string& department = "", int num_courses = 0) :
        UniversityMember(name, department), num_courses(num_courses) 
    {
        course_names = new string[num_courses];
        gpas = new float[num_courses];
    }

    ~Student() {
        delete[] course_names;
        delete[] gpas;
    }

    friend istream& operator>>(istream& in, Student& student) {
        in >> (UniversityMember&)student;
        in >> student.num_courses;
        student.course_names = new string[student.num_courses];
        student.gpas = new float[student.num_courses];
        for (int i = 0; i < student.num_courses; ++i) {
            in >> student.course_names[i] >> student.gpas[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& student) {
        out << (const UniversityMember&)student;
        out << "\nNumber of Courses: " << student.num_courses;
        for (int i = 0; i < student.num_courses; ++i) {
            out << "\nCourse: " << student.course_names[i] << ", GPA: " << student.gpas[i];
        }
        return out;
    }

    bool IsSuccessful() const override {
        float total_gpa = 0.0;
        for (int i = 0; i < num_courses; ++i) {
            total_gpa += gpas[i];
        }
        float cgpa = num_courses > 0 ? total_gpa / num_courses : 0.0;
        return cgpa > 3.0;
    }

    void read() override {
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Student Department: ";
        getline(cin, department);
        cout << "Enter Number of Courses: ";
        cin >> num_courses;
        course_names = new string[num_courses];
        gpas = new float[num_courses];
        for (int i = 0; i < num_courses; ++i) {
            cout << "Enter Course Name: ";
            cin >> course_names[i];
            cout << "Enter GPA for " << course_names[i] << ": ";
            cin >> gpas[i];
        }
        cin.ignore(); // To consume the newline character left in the input buffer
    }

    void write() const override {
        cout << "Name: " << name << "\nDepartment: " << department;
        cout << "\nNumber of Courses: " << num_courses;
        for (int i = 0; i < num_courses; ++i) {
            cout << "\nCourse: " << course_names[i] << ", GPA: " << gpas[i];
        }
    }
};


class Teacher : virtual public UniversityMember {
protected:
    string designation;
    int num_publications;
    int num_courses_offered;
    int num_students_supervised;

public:
    Teacher(
        const string& name = "", const string& department = "", const string& designation = "", int num_publications = 0, int num_courses_offered = 0, int num_students_supervised = 0
        ) : 
        UniversityMember(name, department), designation(designation), num_publications(num_publications), num_courses_offered(num_courses_offered), num_students_supervised(num_students_supervised) 
    {}

    friend istream& operator>>(istream& in, Teacher& teacher) {
        in >> static_cast<UniversityMember&>(teacher);
        in >> teacher.designation >> teacher.num_publications >> teacher.num_courses_offered >> teacher.num_students_supervised;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Teacher& teacher) {
        out << (const UniversityMember&)teacher;
        out << "\nDesignation: " << teacher.designation << "\nNumber of Publications: " << teacher.num_publications << "\nNumber of Courses Offered: " << teacher.num_courses_offered << "\nNumber of Students Supervised: " << teacher.num_students_supervised;
        return out;
    }

    bool IsSuccessful() const override {
        return num_publications > 20;
    }

        void read() override {
        cout << "Enter Teacher Name: ";
        getline(cin, name);
        cout << "Enter Teacher Department: ";
        getline(cin, department);
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Number of Publications: ";
        cin >> num_publications;
        cout << "Enter Number of Courses Offered: ";
        cin >> num_courses_offered;
        cout << "Enter Number of Students Supervised: ";
        cin >> num_students_supervised;
        cin.ignore(); // To consume the newline character left in the input buffer
    }

    void write() const override {
        cout << "Name: " << name << "\nDepartment: " << department;
        cout << "\nDesignation: " << designation;
        cout << "\nNumber of Publications: " << num_publications;
        cout << "\nNumber of Courses Offered: " << num_courses_offered;
        cout << "\nNumber of Students Supervised: " << num_students_supervised;
    }

};


class TeachingAsst : public Student, public Teacher {
private:
    string supervisor;

public:
    TeachingAsst(const string& name = "", const string& department = "", int num_courses = 0, const string& designation = "", int num_publications = 0, int num_courses_offered = 0, int num_students_supervised = 0, const string& supervisor = "")
        : UniversityMember(name, department), Student(name, department, num_courses), Teacher(name, department, designation, num_publications, num_courses_offered, num_students_supervised), supervisor(supervisor) {}

    friend istream& operator>>(istream& in, TeachingAsst& ta) {
        in >> static_cast<Student&>(ta);
        in >> static_cast<Teacher&>(ta);
        in.ignore();
        getline(in, ta.supervisor);
        return in;
    }

    friend ostream& operator<<(ostream& out, const TeachingAsst& ta) {
        out << static_cast<const Student&>(ta);
        out << static_cast<const Teacher&>(ta);
        out << "\nSupervisor: " << ta.supervisor;
        return out;
    }

    bool IsSuccessful() const override {
        return Student::IsSuccessful() && num_courses_offered > 3;
    }

        void read() override {
        Student::read();
        Teacher::read();
        cout << "Enter Supervisor Name: ";
        getline(cin, supervisor);
    }

    void write() const override {
        Student::write();
        Teacher::write();
        cout << "\nSupervisor: " << supervisor;
    }
};


int main() {
    UniversityMember* members[3];

    members[0] = new Student("Alice", "CS", 3);
    members[1] = new Teacher("Bob", "Math", "Professor", 25, 2, 5);
    members[2] = new TeachingAsst("Charlie", "Physics", 4, "Assistant Professor", 10, 4, 8, "Dr. Smith");

    for(int i=0; i<3; i++){
        members[i]->read();
    }

    system("cls");

    for (int i = 0; i < 3; ++i) {
        members[i]->write();
        cout << "\nIs Successful: " << (members[i]->IsSuccessful() ? "Yes" : "No")<<endl;
        cout<<"_______________________________________"<<endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete members[i];
    }

    return 0;
}

/*
    Why we Make Base Class Destructor Virtual?
    
    1. Proper Resource Cleanup: When a base class pointer points to a derived class object and the object is deleted, if the base class destructor is not virtual, only the base class destructor will be called. This can lead to resource leaks because the derived class destructor, which is responsible for cleaning up resources specific to the derived class, will not be called.

    2. Polymorphic Destruction: Declaring the destructor as virtual ensures that the correct destructor (the one corresponding to the actual type of the object) is called, thus allowing proper cleanup of derived class resources.


    Why Constructors Cannot Be Virtual

    1. Object Creation Process: When an object is created, its constructor is responsible for initializing the object. During this process, the type of the object must be fully determined before any constructor code can run. Virtual functions rely on the vtable (virtual table), which is only set up after the constructor of the base class has been executed. Since the constructor's job includes setting up the vtable, it cannot be virtual because it needs to know the exact type of the object before the vtable is set up.

    2. Initialization Order: Constructors are called in a specific order during the object creation process. When a derived class object is created, the base class constructor is called first, followed by the derived class constructor. Making constructors virtual would disrupt this well-defined order and the mechanisms in place to ensure proper object initialization.
    
*/