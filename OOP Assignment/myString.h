#pragma once
#include <iostream>

class myString {
    char* st;
    int length;
public:
    myString(); 
    myString(int);
    myString(const char*);
    myString(const myString&);
    ~myString();

    myString& operator=(const myString&); 
    myString operator+(const myString&) const;
    myString& operator+=(const myString&); 

    char& operator[](int); 
    const char& operator[](int) const;
    myString operator()(int start, int length);
    myString operator()(int start, int length) const;

    bool operator<(const myString&) const;
    bool operator<=(const myString&) const;
    bool operator>(const myString&) const;
    bool operator>=(const myString&) const;
    bool operator==(const myString&) const;
    bool operator!=(const myString&) const;

    friend std::istream& operator>>(std::istream&, myString&);
    friend std::ostream& operator<<(std::ostream&, const myString&);
};
