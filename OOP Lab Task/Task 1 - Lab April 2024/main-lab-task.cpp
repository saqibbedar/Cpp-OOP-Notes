#include <iostream>
using namespace std;

class Mobile{
    private:
    string name;
    int model;

    public:
    // constructor
    Mobile(string name = "xyz", int model = 1234): name(name), model(model){}

    // getters
    string getName(){
        return name;
    }
    int getModel(){
        return model;
    }
    // setters
    void setName(string name){
        this->name = name;
    }
    void setModel(int model){
        model > 0 ? this->model = model : this->model = 0;
    }
    void display(string &name, int &model){
        cout<<"Name: "<<name<<endl;
        cout<<"Model: "<<model<<endl;
    }
};

Mobile modify(Mobile m1, string name, int model){
    m1.setName(name);
    m1.setModel(model);
}

Mobile display(Mobile m){
    cout<<"Name: "<<m.getName()<<endl;
    cout<<"Model: "<<m.getModel()<<endl;
}

int main()
{
    Mobile m1;
    cout<<"Enter mobile name: ";
    string name;
    cin>>name;
    cout<<"Enter mobile model: ";
    int model;
    cin>>model;

    m1.setName(name);
    m1.setModel(model);
    modify(m1, name, model); // for changing values, pass by value
    display(m1);

    return 0;
}