#include "person.h"

// handleCountryCode
int handleCountryCode(int cc)  
{
    // we know country codes are different and are in numbers like: Puerto Rico cc= 1 787, 1 939 etc but we are setting this to test this type of functionality
    if (cc > 0 || cc <= 150)
    {
        return cc; 
    }
    else
    {
        return 92; // default number would be in this case 92
    }
}

// Default constructor
Person::Person() : name(), cnic(), email(), contact_no(), country_code(0), dob()
{
    // cout << "Default constructor of Person" << endl;
}

// Parametrized constructor
Person::Person(const string& name, const string& cnic, const string& email, const string& contact_no, int code, const Date &dob)
{
    this->name = name;
    this->cnic = cnic;
    this->email = email;
    this->contact_no = contact_no;
    country_code = handleCountryCode(code); // to handle the country code
    this->dob = dob;
    // cout << "Parameterized constructor of Person" << endl;
}

// Copy constructor
Person::Person(const Person &other)
{
    name = other.name;
    cnic = other.cnic;
    email = other.email;
    contact_no = other.contact_no;
    country_code = handleCountryCode(other.country_code);
    dob = other.dob;
}

// Destructor
Person::~Person()
{
    // cout << "Destructor of Person" << endl;
}

// Setters
void Person::set_Name(const string& name)
{
    this->name = name;
}
void Person::set_CNIC(const string& cnic)
{
    this->cnic = cnic;
}
void Person::set_Email(const string& email)
{
    this->email = email;
};
void Person::set_Contact_No(const string& contact_no)
{
    this->contact_no = contact_no;
};
void Person::set_country_code(int code)
{
    country_code = handleCountryCode(code);
}
void Person::set_Dob(int d, int m, int y)
{
    dob = Date(d, m, y); // calling Date setter to set the dates of Date object
};

// Getters
string Person::get_Name() const
{
    return name;
};
string Person::get_CNIC() const
{
    return cnic;
};
string Person::get_Email() const
{
    return email;
};
string Person::get_Contact_No() const
{
    return contact_no;
};
int Person::set_country_code() const
{
    return country_code;
}
int Person::get_Dob() const
{
    return dob.getFullDate(); // get Full Date: format [YYMMDD]
};

// Input output functions
void Person::print() const{
    cout<<*this;
}
void Person::read() {
    cin>>*this;
}

ostream &operator<<(ostream &out, const Person &other)
{
    out << "Name: " << other.name << endl
        << "CNIC: " << other.cnic << endl
        << "Email: " << other.email << endl
        << "Contact No: +" << other.country_code << other.contact_no << endl
        << "DOB: " << other.dob;
    return out;
}

istream &operator>>(istream &in, Person &other)
{
    int cc; // country code
    cout << "Enter Name: ";
    getline(in, other.name);
    cout << "Enter CNIC: i.e. [12345-6789012-9]: ";
    getline(in, other.cnic);
    // in >> other.cnic;
    cout << "Enter Email: i.e. [abc@example.com]: ";
    getline(in, other.email);
    // in >> other.email;
    cout << "Enter Country code: [1-150]: ";
    in >> cc;
    other.country_code = handleCountryCode(cc);
    cout << "Enter Contact No: i.e. [3012345678]: ";
    in.ignore();
    getline(in, other.contact_no);
    // in >> other.contact_no;
    in >> other.dob;

    return in;
}