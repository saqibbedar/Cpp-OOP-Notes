#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
    string name;
    string father_name;
    int age;
    float gpa;
    fstream file;

public:
    // Constructor
    Student(string filePath) {
        file.open(filePath, ios::in | ios::out | ios::binary);
        if (!file) {
            cerr << "Error in opening the file...\n";
        }
    }

    // Destructor
    ~Student() {
        file.close();
    }

    void getFunction() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter father's name: ";
        cin >> father_name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter GPA: ";
        cin >> gpa;
    }

    void writeInFile() {
        file.write((char*)this, sizeof(*this));
    }

    void readFromFile() {
        file.seekg(0);
        while (file.read((char*)this, sizeof(*this))) {
            cout << "Student Name: " << name << "\n";
            cout << "Father's Name: " << father_name << "\n";
            cout << "Age: " << age << "\n";
            cout << "GPA: " << gpa << "\n";
        }
    }
};

int main() {
    Student s("student.dat");
    s.getFunction();
    s.writeInFile();
    s.readFromFile();

    return 0;
}

// finally I am back  kafi dair hogai ha mainy koi video nai dali ha aur aj mainy socha kiyon apna channel ko phr sy zinda karon, 

// Mery 15k subscribers, mery channel py 15 hazar subscribers ho gai aur mujhy pata b nai chala, sirf 3 videos hee dali thi aur ab dobara sy kam chalo kiya tu support tu banti ha...

// #include <iostream>
// #include <string>
// #include <fstream>
// using namespace std;

// // fstream file; // creating a file

// class Student
// {
// private:   
//     string name;
//     char father_name[45];
//     int age;
//     float gpa;
    
//     fstream file;
    
// public:

//     // constructor
//     Student(){
//         // set a path for binary file
//         file.open("file.dat", ios::binary | ios::out | ios::in);
//     }

//     // getFunction
//     void get();

//     // write in file
//     void writeInFile(Student &Student);

//     // read from file
//     void readFromFile(Student &Student);

//     // display from file
//     void display();

//     ~Student(){
//         file.close();
//         cout<<"Object destroyed, successfully!";
//     }
// };

// void Student::get(){
//     cout<<"What's name? ";
//     getline(cin, name);
//     cout<<"What's father name? ";
//     cin.ignore();
//     cin.getline(father_name, 45);
//     cout<<"What's age? ";
//     cin>>age;
//     cout<<"What's gpa? "<<endl;
//     cin>>gpa;
// }

// void Student::writeInFile(Student &Student){
//     // write individually each variable 
//     file.write(reinterpret_cast<char*>(&Student), sizeof(Student));
// }

// void Student::readFromFile(Student &Student){
//     file.read(reinterpret_cast<char*> (&Student), sizeof(Student));
// }

// void Student::display(){
//         cout<<"Name: "<<name<<endl;
//         cout<<"Father name: "<<father_name<<endl;
//         cout<<"age: "<<age<<endl;
//         cout<<"gpa: "<<gpa<<endl;
// }

// int main()
// {
//     Student st;
//     st.get();
//     st.writeInFile(st);
//     st.readFromFile(st);
//     st.display();

//     return 0;
// }



// #include <iostream>
// #include <string>
// #include <fstream>
// using namespace std;

// fstream file; // creating a file

// class Student
// {
// private:   
//     string name;
//     char father_name[45];
//     int age;
//     float gpa;
    
// public:

//     // constructor
//     Student(){
//         // set a path for binary file
//         file.open("file.dat", ios::binary);
//     }

//     // getFunction
//     void get();

//     // write in file
//     void writeInFile(string name, char* fName, int age, float gpa);

//     // read from file
//     void readFromFile(string name, char* fName, int age, float gpa);

//     // display from file
//     void display();

//     ~Student(){
//         file.close();
//         cout<<"Object destroyed, successfully!";
//     }
// };

// void Student::get(){
//     cout<<"What's name? ";
//     getline(cin, name);
//     cout<<"What's father name? ";
//     cin.ignore();
//     cin.getline(father_name, 45);
//     cout<<"What's age? ";
//     cin>>age;
//     cout<<"What's gpa? "<<endl;
//     cin>>gpa;
// }

// void Student::writeInFile(string name, char* fName, int age, float gpa){
//     ofstream write("file.dat", ios::binary);
    
//     // write individually each variable 
//     write.write((char*)&name, sizeof(string));
//     write.write((char*)&fName, sizeof(char));
//     write.write((char*)&age, sizeof(int));
//     write.write((char*)&gpa, sizeof(float));
// }

// void Student::readFromFile(string name, char* fName, int age, float gpa){

//     ifstream read("file.dat", ios::binary);

//     read.read((char*)&name, sizeof(string));
//     read.read((char*)&fName, sizeof(char));
//     read.read((char*)&age, sizeof(int));
//     read.read((char*)&name, sizeof(float));
// }

// void Student::display(){
//         cout<<"Name: "<<name<<endl;
//         cout<<"Father name: "<<father_name<<endl;
//         cout<<"age: "<<age<<endl;
//         cout<<"gpa: "<<gpa<<endl;
// }

// int main()
// {
//     Student st;
//     st.get();
//     // st.writeInFile();
//     // st.readFromFile();

//     return 0;
// }