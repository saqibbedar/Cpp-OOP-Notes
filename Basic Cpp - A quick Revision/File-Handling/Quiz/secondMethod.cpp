#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream write;
    write.open("test.md", ios::app);
    write<<"Hello world"<<endl;
    write.close();

    ifstream read;
    read.open("test.md");
    string output;
    getline(read, output);
    cout<<output<<endl;
    read.close();
    
    return 0;
}

