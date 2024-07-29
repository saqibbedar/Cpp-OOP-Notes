#include <iostream>
using namespace std;

class ABC{
    int count;
public:
    ABC(){
        count = 0;
    }
    void push(int val){
        count = val;
    }
    void print(){
        cout<<count<<endl;
    }
};

class DEF : public ABC {
    // modify functions
public:
    void push(int val){
        if(val >= 2){
            cout<<"Exceed limit..."<<endl;
            exit(1);
        }
        ABC::push(val);
    }
};

int main()
{
    DEF xyz;
    ABC gdf;
    gdf.push(1);
    xyz.push(1);
    xyz.print();
    
    return 0;
}