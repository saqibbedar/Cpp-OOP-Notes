// wednesday - 24 april 2024

#include <iostream>
#include <cstring>
using namespace std;

class hello{
    private: 
    void sayHello(){
        cout<<"hello from private"<<endl;
    }
    public:
    void sayHello2(){
        sayHello();
        cout<<"hello from public"<<endl;
    }
};

class abc{
    private:
    int a, b;

    public:
    void set(int x, int y){
        a = x;
        b = y;
    }
    void display(){
        cout<<a<<" "<<b<<endl;
    }
};

// implicit constructor: constructor with no parameters

class Date{
    char day;
public:
// explicit
    Date(char dd){
        day = dd;
    }
    void display(){
        cout<<"Date: "<<day<<endl;
    }
};

void my_fct(Date date){
    date.display();
}

class String{
    char str[100];
    public:
    String(char* s){
        strcpy(str, s);
    }
};

int main()
{
    // hello h;
    // h.sayHello2();
    // abc a, b;
    // a.set(10, 20);
    // b = a;
    // b.display();

    Date a = 'a';
    my_fct(a);

    // String s = "hello";

    return 0;
}