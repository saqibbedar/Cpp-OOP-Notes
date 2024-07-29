#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream win_file("text.dat", ios::binary);

    short a = 9842;

    if(win_file){
        cout<<"ready" <<endl;
        win_file.write((char *)&a, sizeof(a));
    }
    win_file.close();

    ifstream read;
    read.open("text.dat", ios::binary);
    char c;
    while(read.get(c)){
        cout<<c;
    }
    read.close();
    return 0;
}
