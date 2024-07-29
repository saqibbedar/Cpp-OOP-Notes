// Assignment no: 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Task 1 - create record
struct Student{
    char name[50];
    int roll_num; 
    int sem; // semester
    int cpp_results;

    // constructor
    Student(){
        // name = "What's name?"; // showing error while storing value for char-array
        roll_num = 0;
        sem = 0;
        cpp_results = 0;
    }

    // read record
    void read(){
        cout<<"Enter Name: ";
        cin.getline(name, 50);
        cout<<"Enter roll number: ";
        cin>>roll_num;
        cout<<"Enter semester: ";
        cin>>sem;
        cout<<"Enter cpp results: ";
        cin>>cpp_results;
    }
};

// display student data
void display(Student st){
    cout<<"Name: "<< st.name<<endl;
    cout<<"Roll number: "<< st.roll_num <<endl;
    cout<<"Semester: "<<st.sem <<endl;
    cout<<"Cpp results: "<< st.cpp_results<<endl;
}

int main()
{
    Student st; // student obj
    st.read(); // reading student value - (calling from struct)
    
    // write to file
    ofstream write;
    write.open("studentData.txt"); // File Operations

    write << st.name <<endl;
    write << st.roll_num <<endl;
    write << st.sem <<endl;
    write << st.cpp_results <<endl;

    write.close(); // close file

    // read from file
    ifstream read;
    
    // read data from "studentData.txt" file
    read.open("studentData.txt");
    read >> st.name;
    read >> st.roll_num;
    read >> st.sem;
    read >> st.cpp_results;

    display(st); // display data
    read.close(); // close file

    // write to binary file
    ofstream writeBinary("studentData.bin", ios::binary);
    writeBinary.write((char*)&st, sizeof(st));
    writeBinary.close();

    // read from binary file
    Student st_read;
    ifstream read_bin("studentData.bin", ios::binary);
    read_bin.read((char*)&st_read, sizeof(st_read));
    display(st_read);
    read_bin.close();

    return 0;
}