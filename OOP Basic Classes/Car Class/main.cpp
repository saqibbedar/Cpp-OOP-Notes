#include "Car.hpp"

int main(){
    Car c1("BMW", 2020, "Black");
    cout<<"*** Car details ***"<<endl;
    c1.set("Mercedes", 2021, "White");
    c1.display();
    
    return 0;
}