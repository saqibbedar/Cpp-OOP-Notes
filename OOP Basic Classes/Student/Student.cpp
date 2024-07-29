#include "Student.h"

Student::Student(const char *name, int age, int marks[5])
{
    strcpy(this->name, name);
    this->age = age;
    for (int i = 0; i < 5; i++)
    {
        this->marks[i] = marks[i];
    }
}

void Student::inputMarks()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter subject " << i + 1 << " Marks at index [" << i << "]: ";
        cin >> this->marks[i];
    }
}

void Student::input()
{
    cout << "What's name? ";
    cin.getline(this->name, 45);
    cout << "What's age? ";
    cin >> this->age;
    inputMarks();
}

void Student::displayMarks(int marks[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Subject " << i + 1 << " Marks: " << marks[i] << endl;
    }
}

void Student::display()
{
    cout<<"\n********** Student details **********"<<endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    displayMarks(marks);
}