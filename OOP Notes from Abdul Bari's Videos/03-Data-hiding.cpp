// data hiding is achieved with encapsulation, so, let's see how it is achieved
#include <iostream>
using namespace std;

class Rectangle{
    //by default length and breadth are private meaning there by they are not accessible outside the scope of this class but with in the class only!
    int length, breadth;

    public:
        Rectangle(int l= 0, int b=0){
            setLength(l);
            setBreath(b);
        }
        void setLength(int l){
            if(l < 0){
                cout<<"Length can't be -ve: "<<l <<endl;
                length = 1;
            } else length = l;    
        }
        void setBreath(int b){
            if(b < 0) {
                cout<<"breadth can't be -ve: "<<b<<endl; 
                breadth=1;
            } else breadth = b;
        }
        int getLength(){
            return length;
        }
        int getBreadth(){
            return breadth;
        }
        int area(){
            return length * breadth;
        }
        int perimeter(){
            return 2 * (length + breadth);
        }
        // ~Rectangle(){
        // }
};

int main()
{
    Rectangle r;
    r.setLength(10);
    r.setBreath(-5);
    cout<<r.area();
    return 0;
}