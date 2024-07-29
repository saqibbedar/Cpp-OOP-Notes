/*
    Create an abstract class named Patient, which contains:

    Name, cnic, age, contact number, and medical history.

    A constructor with default arguments.

    Overload << and >> operators.

    Write Read() and write() functions which use overloaded >> and << operators of the class to input and output class data members.

    Write calc_bill() function.

    Create a class named OutPatient that inherits from Patient class and contains

    Two data members: discaseType and recommendedMedicine, doc_fee.

    Overloaded << and >> operators and overridden Read and Write Functions. Override calc_bill.

    A constructor with default arguments.

    InPatient named class inherited from class Patient, which holds data members:
    representing the hospital name, ward name, room number, Patient condition, test charges, doc_fee, room_charges_per day, num_of days.

    A constructor with default arguments

    Overloaded << and >> operators and overridden Read and Write function: Override calc bill.

    In the main function, create an array of pointers to base class and create instances of derived classes dynamically. Read and print all data including total bill, Make sure there is no memory leak.

*/

#include <iostream>
#include <string>
using namespace std;

class Patient {
protected:
    string name;
    string cnic;
    int age;
    string contact_number;
    string medical_history;

public:
    Patient(
        const string& name = "", const string& cnic = "", int age = 0, const string& contact_number = "", const string& medical_history = ""
        ) : 
        name(name), cnic(cnic), age(age), contact_number(contact_number), medical_history(medical_history) 
        {}

    virtual ~Patient() {}

    friend istream& operator>>(istream& in, Patient& patient) {
        in >> patient.name >> patient.cnic >> patient.age >> patient.contact_number;
        in.ignore(); // To ignore the newline character before reading the medical history
        getline(in, patient.medical_history);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Patient& patient) {
        out << "Name: " << patient.name << "\nCNIC: " << patient.cnic << "\nAge: " << patient.age << "\nContact Number: " << patient.contact_number << "\nMedical History: " << patient.medical_history;
        return out;
    }

    virtual void read() {
        cin >> *this;
    }

    virtual void write() const {
        cout << *this;
    }

    virtual double calc_bill() const = 0; // Pure virtual function
};


class OutPatient : public Patient {
private:
    string diseaseType;
    string recommendedMedicine;
    double doc_fee;

public:
    OutPatient(
        const string& name = "", const string& cnic = "", int age = 0, const string& contact_number = "", const string& medical_history = "", const string& diseaseType = "", const string& recommendedMedicine = "", double doc_fee = 0.0
    ) : 
        Patient(name, cnic, age, contact_number, medical_history), 
        diseaseType(diseaseType), recommendedMedicine(recommendedMedicine), doc_fee(doc_fee) 
    {}

    friend istream& operator>>(istream& in, OutPatient& patient) {
        in >> static_cast<Patient&>(patient);
        in >> patient.diseaseType >> patient.recommendedMedicine >> patient.doc_fee;
        return in;
    }

    friend ostream& operator<<(ostream& out, const OutPatient& patient) {
        out << static_cast<const Patient&>(patient);
        out << "\nDisease Type: " << patient.diseaseType << "\nRecommended Medicine: " << patient.recommendedMedicine << "\nDoctor Fee: " << patient.doc_fee;
        return out;
    }

    void read() override {
        cin >> *this;
    }

    void write() const override {
        cout << *this;
    }

    double calc_bill() const override {
        return doc_fee;
    }
};


class InPatient : public Patient {
private:
    string hospital_name;
    string ward_name;
    int room_number;
    string patient_condition;
    double test_charges;
    double doc_fee;
    double room_charges_per_day;
    int num_of_days;

public:
    InPatient(
        const string& name = "", const string& cnic = "", int age = 0, const string& contact_number = "", const string& medical_history = "", const string& hospital_name = "", const string& ward_name = "", int room_number = 0, const string& patient_condition = "", double test_charges = 0.0, double doc_fee = 0.0, double room_charges_per_day = 0.0, int num_of_days = 0
        ) : 
        Patient(name, cnic, age, contact_number, medical_history), hospital_name(hospital_name), ward_name(ward_name), room_number(room_number), patient_condition(patient_condition), test_charges(test_charges), doc_fee(doc_fee), room_charges_per_day(room_charges_per_day), num_of_days(num_of_days) 
        {}

    friend istream& operator>>(istream& in, InPatient& patient) {
        in >> static_cast<Patient&>(patient);
        in >> patient.hospital_name >> patient.ward_name >> patient.room_number >> patient.patient_condition >> patient.test_charges >> patient.doc_fee >> patient.room_charges_per_day >> patient.num_of_days;
        return in;
    }

    friend ostream& operator<<(ostream& out, const InPatient& patient) {
        out << static_cast<const Patient&>(patient);
        out << "\nHospital Name: " << patient.hospital_name << "\nWard Name: " << patient.ward_name << "\nRoom Number: " << patient.room_number << "\nPatient Condition: " << patient.patient_condition << "\nTest Charges: " << patient.test_charges << "\nDoctor Fee: " << patient.doc_fee << "\nRoom Charges per Day: " << patient.room_charges_per_day << "\nNumber of Days: " << patient.num_of_days;
        return out;
    }

    void read() override {
        cin >> *this;
    }

    void write() const override {
        cout << *this;
    }

    double calc_bill() const override {
        return test_charges + doc_fee + (room_charges_per_day * num_of_days);
    }
};


int main() {
    Patient* patients[2];

    // Create instances dynamically
    patients[0] = new OutPatient("John Doe", "12345678901", 30, "555-1234", "No history", "Flu", "MedicineA", 50.0);
    patients[1] = new InPatient("Jane Smith", "10987654321", 45, "555-5678", "Diabetes", "City Hospital", "Ward A", 101, "Stable", 200.0, 100.0, 50.0, 3);

    // Read and print all data including total bill
    for (int i = 0; i < 2; ++i) {
        patients[i]->read();
        patients[i]->write();
        cout << "\nTotal Bill: " << patients[i]->calc_bill() << "\n\n";
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < 2; ++i) {
        delete patients[i];
    }

    return 0;
}
