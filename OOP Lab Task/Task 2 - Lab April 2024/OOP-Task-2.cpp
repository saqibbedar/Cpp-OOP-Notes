#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student{
private:
    string name;
    char father_name[45];
    int age;
    float gpa;

public:
    // constructor
    Student(){
        
    };

    // getFunction
    void get();

    // write in file
    void writeInFile();

    // read from file
    void readFromFile();

    // display from file
    void display();

    ~Student(){
        cout<<"Object destroyed successfully!!";
    }
};

void Student::get(){
    cout<<"What's name? ";
    getline(cin, name);
    cout<<"What's father name? ";
    cin.getline(father_name, 45);
    cout<<"What's age? ";
    cin>>age;
    cout<<"What's gpa? ";
    cin>>gpa;
}

void Student::writeInFile(){
    ofstream write("file.dat", ios::binary);
    write.write(name.c_str(), name.size());
    write.write(father_name, sizeof(father_name));
    write.write((char*)&age, sizeof(int));
    write.write((char*)&gpa, sizeof(float));
    write.close();
}

void Student::readFromFile(){
    ifstream read("file.dat", ios::binary);
    char buffer[45];
    read.read(buffer, name.size());
    name = buffer;
    read.read(father_name, sizeof(father_name));
    read.read((char*)&age, sizeof(int));
    read.read((char*)&gpa, sizeof(float));
    read.close();
}

void Student::display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Father name: "<<father_name<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"gpa: "<<gpa<<endl;
}

int main(){
    Student st;
    st.get();
    st.writeInFile();
    st.readFromFile();
    st.display();
    return 0;
}
