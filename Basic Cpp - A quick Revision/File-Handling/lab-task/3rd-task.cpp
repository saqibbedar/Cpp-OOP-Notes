#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream ofile;
    ofile.open("file.md", ios::app | ios::ate);

    int age;
    char name[30];

    ofile.seekp(10, ios::beg);
    ofile.tellp();

    cout<<"enter age: ";                 
    cin>> age;
    cout<<"enter name: ";                 
    cin>>name;

    ofile << age<<endl;
    ofile << name<<endl;
    ofile.close();

    ifstream ifile;
    ifile.open("file.md");

    char c;
    while(ifile.get(c)){
        cout<<c;
    }

    ifile.close();
    return 0;
}


// #include <iostream>
// #include <fstream>

// using namespace std;

// int main(){
//     ofstream ofile;
//     ofile.open("file.md", ios::out | ios::ate);

//     int age;
//     char name[30];

//     ofile.seekp(10, ios::beg); 

//     cout << "enter age: ";
//     cin >> age;

//     cout << "enter name: ";
//     cin >> name;

//     ofile << age << " " << name; 

//     ofile.close(); 
//     return 0;
// }
