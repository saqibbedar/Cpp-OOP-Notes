#include "Car.hpp"

Car::Car(const char *name, int year, const char *color)
{
    strcpy(this->name, name);
    this->year = year;
    strcpy(this->color, color);
}

void Car::set(const char *name, int year, const char *color)
{
    strcpy(this->name, name);
    this->year = year;
    strcpy(this->color, color);
}

void Car::display()
{
    cout << "Name: " << name << endl;
    cout << "Year: " << year << endl;
    cout << "Color: " << color << endl;
}
