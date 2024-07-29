#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream write;
    write.open("hello.md", ios::app);
    // write << "Hello world"<<endl;
    // write.close();

    // char name[40], crs[20];
    // int age, rl;
    // while(cin.getline(name, 40), cin.ignore(), cin.getline(crs, 20), cin>>age, cin>> rl){
    //     cout<<"Enter name: "<< 
    // }

    string name = "saqib";
    const int age = 19;

    write<<name<<endl;
    write<<age<<endl;

    ifstream get_data;
    get_data.open("hello.md");

    
    // while(getline(get_data, name), get_data>>age);

    cout<<name<<endl;
    cout<<age<<endl;

    return 0;
}