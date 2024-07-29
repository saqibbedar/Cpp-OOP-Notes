#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void get(string& text){
    fstream file("file.txt", ios::in);
    !file && cout<<"Error: can't open file!"<<endl;
    string temp;
    while(getline(file, temp)){
        text += temp + "\n";
    }
    file.close();
}

void put(string text){
    fstream file("file.txt", ios::out | ios::app);
    !file && cout<<"Error: can't access file"<<endl;
    file<<text<<endl;
    file.close();
}

int main()
{
    // put data into file
    string msg;
    cout<<"Enter msg to save in file: ";
    getline(cin, msg);
    put(msg);

    system("cls");

    // get data from file
    string text; 
    get(text);
    cout<<text;

    return 0;
}