#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream read;
    read.open("file.yml");

    ofstream write;
    write.open("copiedFile.yml");
    char c;
    while(read.get(c)){
        write<<c;
    }
    read.close();
    write.close();

    return 0;
}