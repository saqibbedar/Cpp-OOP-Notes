#pragma once
#include <iostream>
using namespace std;

class Matrix
{
    int rows;
    int cols;
    int **matrix;

    // allocation & deallocation methods for simplicity
    void alloc();
    void dealloc();

public:
    // constructors
    Matrix();
    Matrix(int);
    Matrix(int, int);
    Matrix(int **, int, int);
    Matrix(const Matrix &);

    // destructor
    ~Matrix();

    // getters & setters
    void setRows(int);
    void setCols(int);
    int getRows() const;
    int getCols() const;

    // friend functions
    friend ostream& operator<<(ostream &, const Matrix &);
    friend istream& operator>>(istream &, Matrix &);

    // operator overloading
    const Matrix& operator+(const Matrix &) const;
    const Matrix& operator-(const Matrix &) const;
    const Matrix& operator*(const Matrix &) const;

    bool operator==(const Matrix &) const;
    bool operator!=(const Matrix &) const;

    int& operator()(int, int);
    const int& operator()(int, int) const;

    int& operator[](int);
    const int& operator[](int) const;
};