#include "arr.h"

MyArray::MyArray(){
    size= 0;
    arr = nullptr;
}
MyArray::MyArray(int s, int val){
    size = s;
    arr = new int[size];
    for(int i=0; i<size; i++){
        arr[i] = val;
    }
}
MyArray::MyArray(const MyArray &other){
    size = other.size;
    arr = new int[size];
    for(int i=0; i<size; i++){
        arr[i] = other.arr[i];
    }
}
MyArray::MyArray(int *a, int s){
    size = s;
    arr = new int[size];
    for(int i=0;i<size;i++){
        arr[i] = a[i];
    }
}
MyArray::~MyArray(){
    delete[] arr;
}
const MyArray &MyArray::operator=(const MyArray &other){
    // check if the object is not being assigned to itself i.e. other = other
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

const int &MyArray::operator[](int index)const{
    if(index < 0 || index >= size){
        cout<<"Index out of range"<<endl;
    }
    return arr[index];
}

int &MyArray::operator[](int index){
    if(index < 0 || index >= size){
        cout<<"Index out of range"<<endl;
    }
    return arr[index];
}

ostream &operator<<(ostream &out, const MyArray &a){
    out<<"[";
    for(int i=0; i< a.size; i++){
        out<<a.arr[i];
        if(i != a.size -1){
            out<<",";
        }
    }
    out<<"]";
    return out;
}

istream &operator>>(istream &in, const MyArray &a){
    for(int i=0; i< a.size; i++){
        in>> a.arr[i];
    }
    return in;
}