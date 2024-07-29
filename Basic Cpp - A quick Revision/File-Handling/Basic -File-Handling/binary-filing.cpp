#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void get(const string& text){
    fstream file("file.bin", ios::in | ios::binary);
    if(!file) {
        cout<<"Error: can't open file."<<endl;
        return;
    }
    file.read((char*)&text, sizeof(text));
    file.close();
}

void put(string text){
    fstream file("file.bin", ios::out | ios::app | ios::binary);
    if(!file) {
        cout<<"Error: file not created."<<endl;
        return;
    }
    file.write((char*)&text, sizeof(text));
    file.close();
}

int main()
{
    // put data into file
    // string msg;
    // cout<<"Enter msg to save in file: ";
    // getline(cin, msg);
    // put(msg);

    // system("cls");

    // get data from file
    string text; 
    get(text);
    cout<<text;

    return 0;
}