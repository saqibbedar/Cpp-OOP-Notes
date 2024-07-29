// Consider following code and guess output, mention if there is any error and fix it then guess output.

#include <iostream>
#include <cstring>
using namespace std;

// class Animal{
//     char name[25];
// public:
//     Animal(char ptr[]){
//         strcpy(name, ptr);
//         cout<<name<<endl;
//     }
//     void run(){
//         cout<<"Animal: "<<name<<" ran.\n";
//     }
// };

// class Dog: public Animal{
//     char name[25];
// public:
//     Dog(char ptr[]): Animal("D"){
//         strcpy(name, ptr);
//         cout<<name<<endl;
//     }
//     void run(){
//         cout<<"Dog: "<<name<<" ran.\n";
//     }
// };

// class Cat: public Animal{
//     char name[25];
// public:
//     Cat(char ptr[]): Animal("C"){
//         strcpy(name, ptr);
//         cout<<name<<endl;
//     }
//     void run(){
//         cout<<"Cat: "<<name<<" ran.\n";
//     }
// };

// class Mouse: public Animal{
//     char name[25];
// public:
//     Mouse(char ptr[]): Animal("M"){
//         strcpy(name, ptr);
//         cout<<name<<endl;
//     }
//     void run(){
//         cout<<"Mouse: "<<name<<" ran.\n";
//     }
// };

// int main()
// {
//     Animal a("Animal"), *pAni;
//     Dog tony("tony");
//     Cat tom("tom");
//     Mouse jerry("jerry");

//     pAni = &a;
//     pAni->run();

//     pAni = &tony;
//     pAni->run();

//     pAni = &tom;
//     pAni->run();

//     pAni = &jerry;
//     pAni->run();

//     return 0;
// }

// correct version of code

class Animal {
    char name[25];
public:
    Animal(const char ptr[]) {
        strcpy(name, ptr);
        cout << name << endl;
    }
    virtual void run() {  // Make it virtual to achieve polymorphism
        cout << "Animal: " << name << " ran.\n";
    }
};

class Dog : public Animal {
    char name[25];
public:
    Dog(const char ptr[]) : Animal("D") {
        strcpy(name, ptr);
        cout << name << endl;
    }
    void run() override {  // Override the run method
        cout << "Dog: " << name << " ran.\n";
    }
};

class Cat : public Animal {
    char name[25];
public:
    Cat(const char ptr[]) : Animal("C") {
        strcpy(name, ptr);
        cout << name << endl;
    }
    void run() override {  // Override the run method
        cout << "Cat: " << name << " ran.\n";
    }
};

class Mouse : public Animal {
    char name[25];
public:
    Mouse(const char ptr[]) : Animal("M") {
        strcpy(name, ptr);
        cout << name << endl;
    }
    void run() override {  // Override the run method
        cout << "Mouse: " << name << " ran.\n";
    }
};

int main() {
    Animal a("Animal"), *pAni;
    Dog tony("tony");
    Cat tom("tom");
    Mouse jerry("jerry");

    pAni = &a;
    pAni->run();  // Animal: Animal ran.

    pAni = &tony;
    pAni->run();  // Dog: tony ran.

    pAni = &tom;
    pAni->run();  // Cat: tom ran.

    pAni = &jerry;
    pAni->run();  // Mouse: jerry ran.

    return 0;
}

/*
output:
    Animal
    D
    tony
    C
    tom
    M
    jerry
    Animal: Animal ran.
    Dog: tony ran.
    Cat: tom ran.
    Mouse: jerry ran.
*/