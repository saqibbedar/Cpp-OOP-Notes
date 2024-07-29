#include <iostream>
#include <fstream>
using namespace std;

int main(){
    // ifstream input("read.md", ios::app);
    // int a;
    // input>>a;
    // input.close();

    fstream outfile;
    outfile.open("read.md", ios::in);
    // outfile<<"Hello world"<<endl;
    // outfile<<"How ara you?"<<endl;
    int x{20};
    outfile>>x;
    return 0;
}