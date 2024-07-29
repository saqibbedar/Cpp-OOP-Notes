#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream get_data_file;
    get_data_file.open("read-cpp-file.cpp");

    char c;
    // one way to get data char by char
    // while(get_data_file >> c){
    //     cout<<c;
    // }

    // second method to get data
    while(get_data_file.get(c)){
        cout<<c;
    }

    // char a[200];
    // while(get_data_file.getline(a, 200, '$')){
    //     cout<<a<<endl;
    // }
    
    get_data_file.close();
    return 0;
}