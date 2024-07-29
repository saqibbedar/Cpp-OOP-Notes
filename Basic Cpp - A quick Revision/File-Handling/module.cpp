#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream output("myFile.md", ios::app); // using ios::app for appending not overriding the values
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    output<<"\n**********"<<"Array"<<"**********\n";
    for(int i=0; i<10; i++){
        output<<arr[i]<<" "; 
    }
    output<<"\n**********"<<"Values"<<"**********\n";
    output<<"\nHello"<<endl;
    output<<"This is C++ filing"<<endl;
    output<<123<<endl
    <<4.567<<endl
    <<'A'<<endl
    <<25*5<<endl;

    cout<<"\n**********"<<"Array Input"<<"**********\n";

    ifstream input("myFile.txt", ios::in);
    int myArr[5];
    int i;
    for(int i=0; i<5; i++){
        input>> myArr[i];
    }
    for(int i=0; i<5; i++){
        output<< myArr[i];
    }

    input.close();
    return 0;
}