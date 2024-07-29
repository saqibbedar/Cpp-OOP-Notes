#include <iostream>
#include <fstream>
// using namespace std;

int main()
{
    int cout = 10;
    std::cout<<cout<<std::endl; // output: 10
    // do you wonder why there is no error? It is because cout is an identifier, it not the language packed word but an object of iostream. So, we can use it as a variable and then wrap cout object with std to point to actual object for printing result to the console.

    int endl = 100;
    std::cout<<endl<<std::endl;

    int cin;
    std::cout<<"Enter a number: ";
    std::cin>>cin;
    std::cout<<"You entered number: "<<cin<<std::endl;


    // file handling part to demonstrate results in a file
    std::ofstream write;
    write.open("03-identifier-result.txt");

    write<<cout<<std::endl;
    write<<endl<<std::endl;
    write<<"Enter a number: ";
    write<<cin<<std::endl;
    write<<"You entered number: "<<cin<<std::endl;

    write.close();

    return 0;
}