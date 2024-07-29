// Assignment no: 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // reading text file - calculating its size
    ifstream readText("studentData.txt");
    readText.seekg(0, ios::end); // move pointer
    int text_size = readText.tellg(); // get position of pointer
    cout<<"Text file size is: "<<text_size<<endl;
    readText.close();

    // reading binary file - calculating its size
    ifstream readBinaryFile("studentData.bin", ios::binary);
    readBinaryFile.seekg(0, ios::end); // move pointer
    int binary_size = readBinaryFile.tellg(); // get the position of pointer
    cout<<"Binary file size is: "<<binary_size<<endl;
    readBinaryFile.close();

    // calculate the size and display difference
    int sizeDifference = abs(text_size - binary_size);
    cout<<"Size difference b/w the text file and the binary file is: "<< sizeDifference<<" bytes "<<endl;

    return 0;
}