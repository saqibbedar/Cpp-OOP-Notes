#include "person.h"

class Student : virtual public Person{
    int semester;
    int total_courses;
    string *subjects;
    int *marks;
    
    public: 
    // constructors
    Student();
    Student(const string&, const string&, const string&, const string&, int, const Date&, int, int, string*, int*);
    Student(const Student &other);
    ~Student();

    // Getters & setters
    void setSemester(int);
    void setTotalCourses(int);
    void setSubjects(const string&, int);
    void setMarks(int, int);

    int getSemester() const;
    int getTotalCourses() const;
    string* getSubjects() const;
    int* getMarks() const;

    // Input output functions
    void print() const override;
    void read() override;

    friend ostream& operator<<(ostream&, const Student &std);
    friend istream& operator>>(istream&, Student &std);

    // creating print_std & read_std functions to avoid duplications in TA class
    friend ostream& print_std(ostream&, const Student&);
    friend istream& read_std(istream&, Student&);

    // calculate grade
    char calcGrade() const;

    // isSuccessful()
    bool isSuccessful() const override;
};
