#include "teacher_assistant.h"

int main()
{
    
    Person* people[3];

    string courses[3] = {"OOP", "Eng", "Mathematics"};
    int marks[3] = {0, 80, 79};

    // Creating dynamic objects
    Student* student = new Student("Saqib Bedar", "12345-6789012-3", "saqib@example.com", "123-4567890", 92, Date(10, 3, 2004), 2, 3, courses, marks);

    student->setSubjects("English", 1); // update the subject from Eng to English
    student->setMarks(99, 0); // update marks

    Faculty* faculty = new Faculty();
    faculty->read();

    TA* ta = new TA();
    ta->read();
    
    people[0] = student;
    people[1] = faculty;
    people[2] = ta;

    system("cls"); // clear screen
    

    for (int i = 0; i < 3; ++i) {
        people[i]->print();
       cout << "\nIs successful: " << (people[i]->isSuccessful() ? "Yes" : "No") << endl;
       cout << "--------------------------------" << endl;
    }

    // deallocate the memory
    for (int i = 0; i < 3; ++i) {
        delete people[i];
    }

    return 0;
}

// Compilation command to run this project in vscode:

// g++ -o output main.cpp date.cpp person.cpp student.cpp faculty.cpp teacher_assistant.cpp 
