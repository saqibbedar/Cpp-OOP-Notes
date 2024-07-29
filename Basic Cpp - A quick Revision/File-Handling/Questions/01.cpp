// Print whole data from the file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string PATH = "C:\\Users\\Saqib Bedar\\Desktop\\OOP Lab Task\\file-handling\\Questions\\dummyText.md";
    string data;

    ifstream read;
    read.open(PATH, ios::in);

    if(!read.is_open()){
        cout<<"Error: while opening file"<<endl;
    }else{
        // while(getline(read, data)){
        //     cout<<data<<endl;
        // }
        // while (!read.eof())
        // {
        //     data = read.get();
        //     cout<<data;
        // }
    }

    read.close();
    return 0;
}