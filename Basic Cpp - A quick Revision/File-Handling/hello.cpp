#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string File = "hello.md";

    ofstream out(File, ios::app);
    // out<<"Hello world"<<endl;

    out.close();

    ifstream in(File);
    string st;
    getline(in, st);
    cout<<st;

    return 0;
}