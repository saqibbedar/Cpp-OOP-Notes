#include <iostream>
#include <string>
#include "date.h"
using namespace std;

class Person{
    string name;
    int cnic; // identification number
    string email;
    int contact_no;
    Date dob; // Date object

public:
    Person();
    Person(string, int, string, int, const Date&);
};

Person::Person():name(){
        name = string(); // calling string default constructor
        cnic = 0;
        email = "abc@example.com"; // passing solid value instead of calling strings default constructor
        contact_no = 0;
        dob = 1; // calling date default constructor
}

Person::Person(string name, int cnic, string email, int contact_no, const Date &dob){
    this->name = name;
    this->cnic = cnic;
    this->email = email;
    this->contact_no = contact_no;
    this->dob = dob;
}

/*
    Different ways to initialize other class constructors, for example, string is a class and we are creating its objects and same we have the Date class and we are also creating its object dob that represents the date of birth of person.

    Now, let's see how we can call the default constructors of other classes 

    Person(){
        Name = string(); // calling default constructor of string
        CNIC = 0;
        Email = string();
        Contact_no = 0;
        dob = Date(); // calling default constructor of string
    }

    ohter way - using heading

    Person() : Name(string()), CNIC(0), Email(string()), Contact_no(0), dob(Date()){}

    !Important: Name(string()) OR Name() are equivalent as in c++ creating object with parenthesis will call always the default constructor of that class

*/