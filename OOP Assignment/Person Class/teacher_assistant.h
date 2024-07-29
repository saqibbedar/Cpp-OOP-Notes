#include "student.h"
#include "faculty.h"

class TA : public Student, public Faculty{
    int no_of_courses_assisting;
    string *assisting_courses_names;
    Faculty *faculty_adviser;
    string thesis_title;

    public:

    // constructors
    TA();
    TA( 
        const string&, const string&, const string&, const string&, int, const Date&, // person class parameters
        int, int, string*, int*, // Student class parameters
        int, const string&, const string&, int, // faculty parameters
        int, string*, Faculty*, const string& // TA parameters
    );
    TA(const TA& other);
    ~TA(); // Destructor

    // setters & getters
    void set_no_of_courses_assisting(int);
    void set_assisting_course_name(const string&, int);
    void set_faculty_adviser(const Faculty &, int);
    void set_thesis_title(const string&);

    int get_no_of_courses_assisting()const;
    string* get_assisting_courses_names()const;
    Faculty* get_faculty_adviser()const;
    string get_thesis_title()const;

    // Input output functions
    void print() const override;
    void read() override;

    friend ostream& operator<<(ostream&, const TA&);
    friend istream& operator>>(istream&, TA&);

    // isSuccessful()
    bool isSuccessful() const override;
};
