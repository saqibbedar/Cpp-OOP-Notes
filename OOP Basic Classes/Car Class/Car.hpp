#pragma once

#include <iostream>
using namespace std;
#include <cstring>

class Car
{
private:
    char name[45];
    int year;
    char color[45];

public:

    Car(const char *name, int year, const char *color);

    void set(const char *name, int year, const char *color);
    void display();

    ~Car(){};
};
