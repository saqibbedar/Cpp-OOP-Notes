#include "myString.h"
#include <cstring>


myString::myString() : st(nullptr), length(0) {}


myString::myString(int size)  {
    length = size;
    st = new char[length + 1];
    st[0] = '\0';
}


myString::myString(const char* s) {
    length = strlen(s);
    st = new char[length + 1];
    strcpy(st, s);
}


myString::myString(const myString& other) {
    length = other.length;
    st = new char[length + 1];
    strcpy(st, other.st);
}


myString::~myString() {
    delete[] st;
}


myString& myString::operator=(const myString& other) {
    if (this != &other) {
        delete[] st;
        length = other.length;
        st = new char[length + 1];
        strcpy(st, other.st);
    }
    return *this;
}


myString myString::operator+(const myString& other) const {
    myString temp=length + other.length;
    strcpy(temp.st, st);
    strcat(temp.st, other.st);
    return temp;
}


myString& myString::operator+=(const myString& other) {
   
    *this = *this + other;
    return *this;
}


char& myString::operator[](int index) {
    return st[index];
}

const char& myString::operator[](int index) const {
    return st[index];
}


myString myString:: operator()(int start, int length) {
    myString temp;
    temp.st = new char[length + 1];
    for (int i = 0; i < length; i++) {
        temp.st[i] = st[start + i];
    }
    temp.st[length] = '\0';
    temp.length = length;
    return temp;
}


myString myString :: operator()(int start, int length) const {
    myString temp;
    temp.st = new char[length + 1];
    for (int i = 0; i < length; i++) {
        temp.st[i] = st[start + i];
    }
    temp.st[length] = '\0';
    temp.length = length;
    return temp;
}


bool myString::operator<(const myString& other) const {
    return (strcmp(st, other.st) < 0);
}

bool myString::operator<=(const myString& other) const {
    return (strcmp(st, other.st) <= 0);
}

bool myString::operator>(const myString& other) const {
    return (strcmp(st, other.st) > 0);
}

bool myString::operator>=(const myString& other) const {
    return (strcmp(st, other.st) >= 0);
}

bool myString::operator==(const myString& other) const {
    return (strcmp(st, other.st) == 0);
}

bool myString::operator!=(const myString& other) const {
    return (strcmp(st, other.st) != 0);
}

std::ostream& operator<<(std::ostream& os, const myString& s) {
    os << s;
    return os;
}


std::istream& operator>>(std::istream& is, myString& s) {
    
    is >> s;
    return is;
}
