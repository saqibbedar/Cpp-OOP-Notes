#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

int main(){
    Date Events[5];
    ifstream read;
    read.open("03-struct-events.txt");
    string temp;

    for (int i = 0; i < 5; i++)
    {
        getline(read, temp); // Read and discard the question about the day
        read >> Events[i].day;
        getline(read, temp); // Read and discard the rest of the line

        getline(read, temp); // Read and discard the question about the month
        read >> Events[i].month;
        getline(read, temp); // Read and discard the rest of the line

        getline(read, temp); // Read and discard the question about the year
        read >> Events[i].year;
        getline(read, temp); // Read and discard the rest of the line
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Your event " << i + 1 << " will be held on : " << Events[i].day << "/" << Events[i].month << "/" << Events[i].year << endl;
    }

    read.close();
    return 0;
}