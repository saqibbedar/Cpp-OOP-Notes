#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    // string arr[5];
    // cout<<"Enter 5 names: ";
    // for(int i=0; i<5; i++){
    //     getline(cin, arr[i]);
    // }

    // ofstream write("file.yml", ios::app);
    // for(int i=0; i<5; i++){
    //     write<<arr[i]<<endl;
    // }
    // write.close();

    ifstream read("file.yml");
    string st;
    while(getline(read, st)){
        cout<<st<<endl;
    }
    read.close();

    return 0;
}