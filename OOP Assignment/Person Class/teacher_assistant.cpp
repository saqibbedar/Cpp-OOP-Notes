#include "teacher_assistant.h"

// Default constructor
TA::TA(): 
    Student(), // default constructor would be called of student
    Faculty(), // Faculty default constructor
    no_of_courses_assisting(0), assisting_courses_names(nullptr), faculty_adviser(nullptr), thesis_title("") // TA parameters
{}

// parameterized constructor
TA::TA(
        const string& name, const string& cnic, const string& email, const string& contact_no, int code, const Date &dob, // person class parameters
        int sem, int courses, string *sub, int *m, // Student class parameters
        int sal, const string& qual, const string& exp, int pp, // faculty parameters
        int n_of_c, string* assisting_courses, Faculty* fac_adv, const string& th_title // TA parameters
    ): 
    Student(name, cnic, email, contact_no, code, dob, sem, courses, sub, m),
    Faculty(name, cnic, email, contact_no, code, dob, sal, qual, exp, pp),
    no_of_courses_assisting(n_of_c), thesis_title(th_title)
{
    assisting_courses_names = new string[no_of_courses_assisting];

    for(int i=0; i<no_of_courses_assisting; i++){
        assisting_courses_names[i] = assisting_courses[i];
    }

    faculty_adviser = fac_adv;
}

// copy constructor
TA::TA(const TA& other):
    Student(other), // Student copy constructor
    Faculty(other), // Faculty copy constructor
    
    // TA copy constructor
    no_of_courses_assisting(other.no_of_courses_assisting),
    thesis_title(other.thesis_title)
{
    assisting_courses_names = new string[no_of_courses_assisting];
    for(int i=0; i<no_of_courses_assisting; i++){
        assisting_courses_names[i] = other.assisting_courses_names[i];
    }

    faculty_adviser = other.faculty_adviser;
}

// Destructor
TA::~TA(){
    delete[] assisting_courses_names;
    delete[] faculty_adviser;
}


// Setters
void TA::set_no_of_courses_assisting(int n_of_c){
    no_of_courses_assisting = n_of_c;
}
void TA::set_assisting_course_name(const string& course_name, int index){
    if(index < 0 || index > no_of_courses_assisting)
        cout<<"Error: index is undefined!"<<endl;
    else 
        assisting_courses_names[index] = course_name;
}
void TA::set_faculty_adviser(const Faculty &fa, int index){
    if(index < 0 || index > no_of_courses_assisting)
        cout<<"Error: index is undefined!"<<endl;
    else 
        faculty_adviser[index] = fa;
}
void TA::set_thesis_title(const string& th_title){
    thesis_title = th_title;
}   

// Getters
int TA::get_no_of_courses_assisting()const{
    return no_of_courses_assisting;
}
string* TA::get_assisting_courses_names()const{
    return assisting_courses_names;
}
Faculty* TA::get_faculty_adviser()const{
    return faculty_adviser;
}
string TA::get_thesis_title()const{
    return thesis_title;
}

// Input output methods
void TA::print() const{
    cout << "\n\n***** TA Information *****\n"<<endl;
    cout<<*this;
}
void TA::read(){
    cout << "\n\n***** Enter TA Information *****\n"<<endl;
    cin>>*this;
}

ostream& operator<<(ostream& out, const TA& t_a){
    out<<(const Person&)t_a<<endl;
    print_std(out, t_a)<<endl;
    printFaculty(out, t_a)<<endl;
    out
    <<"No. of courses Assisting: "<<t_a.no_of_courses_assisting<<endl
    <<"Courses Assisting: [";
    for(int i=0; i<t_a.no_of_courses_assisting; i++){
        if(i == t_a.no_of_courses_assisting -1){
            out<<t_a.assisting_courses_names[i];
        }else{
            out<<t_a.assisting_courses_names[i]<<", ";
        }
    }
    out<<"] "<<endl
    <<"Thesis title: "<<t_a.thesis_title<<endl;

    return out;
}
istream& operator>>(istream& in, TA& t_a){
    cin.ignore();
    in>>(Person&)t_a;
    read_std(in, t_a);
    readFaculty(in, t_a);
    cout<<"Enter No. of courses assisting: ";
    in>>t_a.no_of_courses_assisting;
    t_a.assisting_courses_names = new string[t_a.no_of_courses_assisting];
    cout<<"Enter Names of courses assisting: \n";
    for(int i=0; i<t_a.no_of_courses_assisting; i++){
        in>>t_a.assisting_courses_names[i];
    }
    cout<<"Enter thesis title: ";
    in>>t_a.thesis_title;

    return in;
}

// isSuccessful? 
bool TA::isSuccessful() const {
    bool studentSuccess = Student::isSuccessful();
    bool assistingSuccess = no_of_courses_assisting >= 2;
    bool publicationSuccess = get_paper_published() >= 1;
    return studentSuccess && (assistingSuccess || publicationSuccess);
}
