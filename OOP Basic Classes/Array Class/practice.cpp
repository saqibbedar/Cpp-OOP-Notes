#include <iostream>
#include <ostream>
using namespace std;

class MyArray
{
    int size;
    int *arr;
    friend ostream& operator<<(ostream&, const MyArray&);
    friend istream& operator>>(istream&, MyArray&);

public:
    // default constructor
    MyArray();
    // overloaded parameterized constructor
    MyArray(int, int);
    // parameterized constructor
    MyArray(int *, int);
    // copy constructor
    MyArray(const MyArray &);
    // destructor
    ~MyArray();

    // operator overloading
    const MyArray& operator=(const MyArray&);
};

// friend functions
ostream& operator<<(ostream& print, const MyArray &obj){
    print<<"[";
    for(int i=0; i<obj.size; i++){
        print<<obj.arr[i];
    }
    print<<"]";
    return print;
}
istream& operator>>(istream& input, MyArray &obj){
    for(int i=0; i< obj.size;i++){
        input>>obj.arr[i];
    }
    return input;
}

// constructors
MyArray::MyArray()
{
    size = 0;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
}
MyArray::MyArray(int s, int val)
{ // val = value
    size = s;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}
MyArray::MyArray(int *a, int size)
{
    this->size = size;
    arr = new int[this->size];
    for (int i = 0; i < this->size; i++)
    {
        arr[i] = a[i];
    }
}
MyArray::MyArray(const MyArray &other)
{
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
}
// Destructor
MyArray::~MyArray()
{
    delete[] arr;
}

// operator overloading

// overload assignment operator
const MyArray& MyArray::operator=(const MyArray &other){
    if(this != &other){
        delete[] arr;
        size = other.size;
        arr = new int[size];
        for(int i=0; i<size; i++){
            arr[i] = other.arr[i];
        }
    }
    return *this;
}


int main()
{

    return 0;
}