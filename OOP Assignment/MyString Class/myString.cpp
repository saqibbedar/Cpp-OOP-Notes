#include <iostream>
#include <cstring>
using namespace std;

class myString {
private:
    char* str;
    int size;

    int strlen(const char*);
    char* strcpy(char*, const char*);
    char* strcat(char*, const char*);
    friend ostream& operator<<(ostream&, const myString&);

public:
    // constructors
    myString();
    myString(const char*);
    myString(const myString&);
    ~myString(); // destructor

    int length() const;
    int strcmp(const myString&) const;

    // Operator overloading
    myString operator+(const myString&) const;
    myString& operator+=(const myString&);
    bool operator==(const myString&) const;
    bool operator!=(const myString&) const;
    bool operator<(const myString&) const;
    bool operator>(const myString&) const;
    bool operator>=(const myString&) const;
    bool operator<=(const myString&) const;
    myString& operator=(const myString&);
    char& operator[](int index);
    const char& operator()(int index) const;
    istream& getline(istream&, int);
};

// constructors
myString::myString() : str(new char[1]{'\0'}), size(0) {}

myString::myString(const char* s) : size(strlen(s)) {
    str = new char[size + 1];
    strcpy(str, s);
}

myString::myString(const myString& s) : size(s.size) {
    str = new char[size + 1];
    strcpy(str, s.str);
}

// destructor
myString::~myString() {
    delete[] str;
    str = nullptr;
}

int myString::strlen(const char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char* myString::strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* myString::strcat(char* dest, const char* src) {
    int dest_len = strlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

int myString::length() const {
    return size;
}

int myString::strcmp(const myString& s) const {
    return std::strcmp(str, s.str);
}

myString myString::operator+(const myString& s) const {
    myString res;
    res.size = size + s.size;
    delete[] res.str;
    res.str = new char[res.size + 1];
    strcpy(res.str, str);
    strcat(res.str, s.str);
    return res;
}

myString& myString::operator+=(const myString& s) {
    *this = *this + s;
    return *this;
}

bool myString::operator<(const myString& s) const {
    return strcmp(s) < 0;
}

bool myString::operator>(const myString& s) const {
    return strcmp(s) > 0;
}

bool myString::operator==(const myString& s) const {
    return strcmp(s) == 0;
}

bool myString::operator!=(const myString& s) const {
    return strcmp(s) != 0;
}

bool myString::operator>=(const myString& s) const {
    return strcmp(s) >= 0;
}

bool myString::operator<=(const myString& s) const {
    return strcmp(s) <= 0;
}

myString& myString::operator=(const myString& s) {
    if (this != &s) {
        delete[] str;
        size = s.size;
        str = new char[size + 1];
        strcpy(str, s.str);
    }
    return *this;
}

char& myString::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return str[index];
}

const char& myString::operator()(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return str[index];
}

istream& myString::getline(istream& in, int size) {
    delete[] str;
    str = new char[size + 1];
    in.getline(str, size + 1);
    this->size = strlen(str);
    return in;
}

ostream& operator<<(ostream& out, const myString& s) {
    out << s.str;
    return out;
}

int main() {
    myString s1("Hello");
    myString s2("World");
    myString s3 = s1 + s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s1 + s2: " << s3 << endl;
    
    s1 += s2;
    cout << "s1 after += s2: " << s1 << endl;
    
    cout << "Comparison (s1 == s3): " << (s1 == s3) << endl;
    cout << "Comparison (s1 != s2): " << (s1 != s2) << endl;
    cout << "Comparison (s1 < s2): " << (s1 < s2) << endl;
    cout << "Comparison (s1 > s2): " << (s1 > s2) << endl;
    cout << "Comparison (s1 >= s3): " << (s1 >= s3) << endl;
    cout << "Comparison (s1 <= s3): " << (s1 <= s3) << endl;

    try {
        cout << "s1[1]: " << s1[1] << endl;
        cout << "s1(1): " << s1(1) << endl;
        cout << "s1[10]: " << s1[10] << endl;  // Should throw an exception
    } catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }

    myString s4;
    cout << "Enter a string: ";
    s4.getline(cin, 10);
    cout << "You entered: " << s4 << endl;

    return 0;
}
