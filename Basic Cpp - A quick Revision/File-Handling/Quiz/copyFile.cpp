#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ifstream read;
    read.open("test.md");

    ofstream write;
    write.open("file.md");

    string str;
    while(getline(read, str)){
        write<<str<<endl;
    };
    
    return 0;
}
