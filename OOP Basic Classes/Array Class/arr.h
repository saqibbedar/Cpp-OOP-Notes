#pragma once
#include <iostream>
#include <ostream>
using namespace std;

class MyArray
{
    int size;
    int *arr;
    friend ostream &operator<<(ostream &, const MyArray &);
    friend istream &operator>>(istream &, const MyArray &);

public:
    MyArray();
    MyArray(int, int = 0);
    MyArray(const MyArray &);
    MyArray(int *, int);
    ~MyArray(); 

    // copy assignment operator
    const MyArray& operator=(const MyArray &);
    // array subscript operator
    const int &operator[](int) const;
    // array subscript operator for updating value
    int &operator[](int);
};