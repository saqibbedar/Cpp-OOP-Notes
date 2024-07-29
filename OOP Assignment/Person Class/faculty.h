#include "person.h"

class Faculty : virtual public Person
{
    int salary;
    string qualification;
    string area_of_expertise; 
    int paper_published;

public:
    // constructors
    Faculty();
    Faculty(const string&, const string&, const string&, const string&, int, const Date &, int, const string&, const string&, int);
    Faculty(const Faculty &other);
    ~Faculty();

    // Getters & setters
    void set_salary(int);
    void set_qualification(const string&);
    void set_area_of_expertise(const string&);
    void set_paper_published(int);

    int get_salary() const;
    string get_qualification() const;
    string get_area_of_expertise() const;
    int get_paper_published() const;

    // Input output functions 
    void print() const override;
    void read() override;

    friend ostream &operator<<(ostream&, const Faculty &);
    friend istream &operator>>(istream&, Faculty &);

    // creating printFaculty & readFaculty functions to avoid duplications in TA class
    friend ostream& printFaculty(ostream&, const Faculty&);
    friend istream& readFaculty(istream&, Faculty&);

    // isSuccessful()
    bool isSuccessful() const override;
};
