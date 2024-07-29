// creates events using structure

#include <iostream>
#include <fstream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

int main()
{
    Date Events[5]; // five events on which you will do different tasks

    for (int i = 0; i < 5; i++)
    {
        cout << "what's Events " << i + 1 << " day? ";
        cin >> Events[i].day;
        cout << "what's Events " << i + 1 << " month? ";
        cin >> Events[i].month;
        cout << "what's Events " << i + 1 << " year? ";
        cin >> Events[i].year;
    }

    // print the events
    for (int i = 0; i < 5; i++)
    {
        cout << "Your event " << i + 1 << " will be held on : " << Events[i].day << "/" << Events[i].month << "/" << Events[i].year << endl;
    }

    ofstream write;
    write.open("03-struct-events.txt");
    for (int i = 0; i < 5; i++)
    {
        write << "what's Events " << i + 1 << " day? ";
        write << Events[i].day;
        write << "what's Events " << i + 1 << " month? ";
        write << Events[i].month;
        write << "what's Events " << i + 1 << " year? ";
        write << Events[i].year;
    }

    for (int i = 0; i < 5; i++)
    {
        write << "Your event " << i + 1 << " will be held on : " << Events[i].day << "/" << Events[i].month << "/" << Events[i].year << endl;
    }

    write.close();

    return 0;
}