#include <iostream>
using namespace std;

// Our structure
struct Date {
    int day;
    int month;
    int year;
};

void data(Date &event){
    cout<<"Enter event day: ";
    cin>>event.day;
    cout<<"Enter event month: ";
    cin>>event.month;
    cout<<"Enter event year: ";
    cin>>event.year;
}

void readData(Date* events, int size){
    Date *temp = events;
    for(int i=0; i<size; i++){
        data(*temp); // OR use data(*(events+i))
        temp++;
    }
}

void display(Date* date, int size){
    for(int i=0, c=1; i<size; i++, c++){
        cout<<"Event " <<c<<" : "<<date[i].day<<"/"<<date[i].month<<"/"<<date[i].year<<endl;
    }
}

int main()
{
    int size;
    cout<<"Enter the size of Events: ";
    cin>>size;

    Date* events = new Date[size]; // Dynamic array
    readData(events, size); // get events data
    display(events, size); // display the events data

    delete[] events;
    return 0;
}