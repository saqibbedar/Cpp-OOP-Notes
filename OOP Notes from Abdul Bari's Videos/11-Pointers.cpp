#include <iostream>

class Rectangle {
    private: 
        int length;
        int breath;
    public:
    int area(int l, int b){
        length = l;
        breath = b;
        return length * breath;
    }
};

int main(){
    Rectangle *ptr = new Rectangle();
    std::cout<<ptr->area(10, 5);

    delete ptr;
    return 0;
}
