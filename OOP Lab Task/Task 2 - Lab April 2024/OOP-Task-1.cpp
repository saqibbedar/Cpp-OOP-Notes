#include <iostream>
#include <string>
using namespace std;

class Car {
    string name;
    string model;
    int year;
    double price;

public:
    
    // non-parameterized constructor
    Car(){
        name = "Hello, world";
        model = "kuch bhi";
        year = 0;
        price = 0.0;
    }

    // Parameterized constructor
    Car(string name = "Hello, world", string model = "XYZ", int year = 0, double price = 0.0){
        set(name, model, year, price);
    }   
    // set method
    void set(string name, string model, int year, double price){
        this->name = name;
        this->model = model;
        this->year = year;
        this->price = price;
    }
    // show the data
    void display(){
        cout<<"Name: "<< this->name<<endl;
        cout<<"Model: "<< this->model<<endl;
        cout<<"Year: "<< this->year<<endl;
        cout<<"Price: $"<<this->price<<endl;
    }

    // destructor
    ~Car(){
        cout<<"Object destroyed"<<endl;
    }
};

int main()
{
    Car c1("BMW", "XYZ", 2000, 2000);
    c1.display();
    return 0;
}