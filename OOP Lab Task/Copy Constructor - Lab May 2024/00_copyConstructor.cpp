// A copy constructor is a member function which initializes an object using another object of the same class.

// copy constructor: if don't write this still compiler will generate it. So, comment it and try run the program you will get the same results.

#include <iostream>
using namespace std;

class CopyConstructor{
    int a;
    public:
    CopyConstructor(){
        a = 0;
    }
    CopyConstructor(int x){
        a = x;
    }
    
    CopyConstructor(const CopyConstructor &obj){
        a = obj.a;
    }

    friend void display(CopyConstructor &obj);
};

void display(CopyConstructor &obj){
    cout<<obj.a<<endl;
}

int main(){
    CopyConstructor obj;
    CopyConstructor obj2 = 20;
    obj = obj2;

    cout<<"value of obj: ";
    display(obj2);
    cout<<"value of obj2: ";
    display(obj);

    obj = 30;
    obj2 = 40;
    // swap values
    CopyConstructor temp = obj;
    obj = obj2;
    obj2 = temp;
    
    cout<<"\n               Swapped values          \n"<<endl;
    cout<<"value of obj: ";
    display(obj);
    cout<<"value of obj2: ";
    display(obj2);
    
    return 0;
}