#include "faculty.h"

Faculty::Faculty() : Person(), salary(0), qualification(""), area_of_expertise(""), paper_published(0){};

// Parameterized constructor
Faculty::Faculty(
    const string& name, const string& cnic, const string& email, const string& contact_no, int code, const Date &dob, // person parameters
    int sal, const string& qual, const string& exp, int pp // faculty parameters
    ) : 
    Person(name, cnic, email, contact_no, code, dob), 
    salary(sal), qualification(qual), area_of_expertise(exp), paper_published(pp) 
    {}

// Copy constructor
Faculty::Faculty(const Faculty &other) : 
Person(other), 
salary(other.salary), qualification(other.qualification), area_of_expertise(other.area_of_expertise), paper_published(other.paper_published) 
{}

// Destructor
Faculty::~Faculty() {}

// Setters
void Faculty::set_salary(int s)
{
    salary = s;
};
void Faculty::set_qualification(const string& q)
{
    qualification = q; 
};
void Faculty::set_area_of_expertise(const string& e)
{
    area_of_expertise = e;
};
void Faculty::set_paper_published(int pp)
{
    paper_published = pp;
};

// Getters
int Faculty::get_salary() const
{
    return salary;
};
string Faculty::get_qualification() const
{
    return qualification;
};
string Faculty::get_area_of_expertise() const
{
    return area_of_expertise;
};
int Faculty::get_paper_published() const
{
    return paper_published;
};

// Input output functions
void Faculty::print() const{
    cout << "\n\n***** Faculty Member Information *****\n"<<endl;
    cout<<*this;
}
void Faculty::read(){
    cout << "\n\n***** Enter Faculty Member Information *****\n"<<endl;
    cin>>*this;
}

ostream &operator<<(ostream &out, const Faculty &f) // f = faculty
{
       out
        << (const Person &)f << endl
        << "Salary: " << f.salary << endl
        << "Qualification: " << f.qualification << endl
        << "Area of Expertise: " << f.area_of_expertise << endl
        << "Published Papers: " << f.paper_published;
    return out;
}
istream &operator>>(istream &in, Faculty &f)
{
    in >> (Person &)f;
    cout << "Enter salary: ";
    in >> f.salary;
    cout << "Enter qualification: ";
    in.ignore();
    getline(in, f.qualification);
    cout << "Enter Area of Expertise: ";
    getline(in, f.area_of_expertise);
    cout << "Enter No. Published Papers: ";
    in >> f.paper_published;
    return in;
}

ostream& printFaculty(ostream& out, const Faculty& f){
    out
        << "Salary: " << f.salary << endl
        << "Qualification: " << f.qualification << endl
        << "Area of Expertise: " << f.area_of_expertise << endl
        << "Published Papers: " << f.paper_published;
    return out;
}

istream& readFaculty(istream& in, Faculty& f){
    cout << "Enter salary: ";
    in >> f.salary;
    cout << "Enter qualification: ";
    in.ignore();
    getline(in, f.qualification);
    cout << "Enter Area of Expertise: ";
    getline(in, f.area_of_expertise);
    cout << "Enter No. Published Papers: ";
    in >> f.paper_published;
    return in;
}

// isSuccessful?
bool Faculty::isSuccessful() const {
    return paper_published >= 10;
}
