#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // writing in a file
    // ofstream write("file.md", ios::app); // create file
    // write << "Hello world" << endl;      // write in file
    // write.close();

    // reading from a created file
    ifstream read("file.md");
    string st;
    getline(read, st);
    cout << st;

    return 0;
}