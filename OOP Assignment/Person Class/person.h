#pragma once
#include <string>
#include "date.h"

class Person
{
    string name;
    string cnic; // identification number
    string email;
    string contact_no;
    int country_code;            // extra variable for country code
    Date dob;                    // Date object
    friend int handleCountryCode(int); // to manage country code
 
public:
    // constructors
    Person();
    Person(const string&, const string&, const string&, const string&, int, const Date &);
    Person(const Person &);
    virtual ~Person(); // Destructor

    // getters & setters
    virtual void set_Name(const string&);
    virtual void set_CNIC(const string&);
    virtual void set_Email(const string&);
    virtual void set_Contact_No(const string&);
    virtual void set_country_code(int);
    virtual void set_Dob(int, int, int);

    virtual string get_Name() const;
    virtual string get_CNIC() const;
    virtual string get_Email() const;
    virtual string get_Contact_No() const;
    virtual int set_country_code() const;
    virtual int get_Dob() const;

    // Input output functions
    virtual void print() const;
    virtual void read();

    friend ostream &operator<<(ostream &, const Person &);
    friend istream &operator>>(istream &, Person &);

    // isSuccessful()
    virtual bool isSuccessful() const = 0;
};
