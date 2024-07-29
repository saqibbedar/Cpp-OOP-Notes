#include <iostream>
#include <fstream>
using namespace std;

struct Student{
    int id;
    char name[40];
    int marks;
};  

int main()
{
    // Student st[5] = {
    //     {1, "hello", 80},
    //     {2, "hello world", 90},
    //     {3, "hello world, welcome to c++ course", 70}
    // };

    // // save data in file
    // ofstream output;
    // output.open("struct.md", ios::app);

    // int i;
    // for(i = 0; i<3; i++){
    //     output<<st[i].id<<endl;
    //     output<<st[i].name<<endl;
    //     output<<st[i].marks<<endl;
    // }
    // output.close(); 

    // read data from file
    ifstream input;
    input.open("struct.md");

    // reading data from file
    // int i;
    // for(i = 0; i<3; i++){
    //     input>>st[i].id;
    //     input.ignore();
    //     input.getline(st[i].name, 40);
    //     input>>st[i].marks;
    // }

    // // printing result to the console
    // for(i = 0; i<3; i++){
    //     cout<<st[i].id<<endl;
    //     cout<<st[i].name<<endl;
    //     cout<<st[i].marks<<endl;
    // }

    // update version
    char c;

    while(input.get(c)){
        cout<<c;
    }

    input.close();
    
    return 0;
}
