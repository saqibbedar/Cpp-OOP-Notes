#include <iostream>

class Rectangle {
    private:
        int length;
        int breath;
    public:
        int setLength(int l){
            length = l;
        }
        int setBreath(int b){
            breath = b;
        }
        int getLength(){
            return length;
        }
        int getBreath(){
            return breath;
        }
        int area(){
            return length * breath;
        }
};

int main(){
    Rectangle r1;
    r1.setLength(10);
    r1.setBreath(5);
    std::cout << "Area of Rectangle is: " << r1.area() << std::endl;

    return 0;
}