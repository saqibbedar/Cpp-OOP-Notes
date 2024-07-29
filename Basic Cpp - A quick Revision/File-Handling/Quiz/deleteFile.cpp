#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int value = remove("file.md");

    value == 0 ? cout<<"File deleted" : cout<<"File does not delete";
    
    return 0;
}
