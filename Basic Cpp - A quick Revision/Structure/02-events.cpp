// creates events using structure

#include <iostream>
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
        cout << "what's Events "<<i+1<<" day? ";
        cin >> Events->day;
        cout << "what's Events "<<i+1<<" month? ";
        cin >> Events->month;
        cout << "what's Events "<<i+1<<" year? ";
        cin >> Events->year;
    }

    // print the events
    for (int i = 0; i < 5; i++)
    {
        cout << "Your event " << i + 1 << " will be held on : " << Events->day << "/" << Events->month << "/" << Events->year<<endl;
    }
    return 0;
}