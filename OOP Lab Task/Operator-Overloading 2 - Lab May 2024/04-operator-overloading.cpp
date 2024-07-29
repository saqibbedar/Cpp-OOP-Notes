// #pragma once
#include <ostream>
#include <iostream>
using namespace std;

class ABC{
    int x;
    public:
    ABC():x(0){}
    ABC(int y):x(y){}
    ABC(const ABC& a){
        x = a.x;
    }
    friend ostream& operator<<(ostream&, const ABC&);
    friend istream& operator>>(istream&, ABC&);
    bool operator<(const ABC&)const;
    bool operator==(const ABC&)const;
    ABC operator+(const ABC&)const;
    ABC& operator++(int);
    ABC& operator--(int);
    
};

ABC& ABC::operator--(int){
    x-=1;
    return *this;
}
ABC& ABC::operator++(int){
    x += 1;
    return *this;
}

ABC ABC::operator+(const ABC& a)const{
    return ABC(this->x + a.x);
}

bool ABC::operator==(const ABC &a)const{
    return this->x == a.x;
}
bool ABC::operator<(const ABC &a)const{
    return this->x < a.x;
}

ostream& operator<<(ostream &print, const ABC &a){
    print<<a.x;
    return print;
}

istream& operator>>(istream &output, ABC &a){
    output>>a.x;
    return output;
}

int main(){
    ABC a, b;
    cout<<"Enter number: ";
    cin>>a>>b;
    cout<<"You entered: "<<a<<", "<<b<<endl;
    if(a<b) cout<<a<<" < "<<b<<endl;
    (a == b)? cout<<"Both are equal"<<endl : cout<<"";

    ABC sum = a+b;
    cout<<sum<<endl;
    sum++;
    cout<<sum<<endl;
    sum--;
    cout<<sum<<endl;

    return 0;
}