#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    char name[45];
    int marks[5];
    int age;

public:
    Student(const char *name, int age, int marks[5]);
    void inputMarks();
    void input();
    void displayMarks(int marks[5]);
    void display();
    ~Student(){}
};