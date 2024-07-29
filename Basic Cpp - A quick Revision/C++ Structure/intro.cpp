#include <iostream>
using namespace std;

// We use array to hold multiple values at same time with same datatype but what if we want values in different datatypes, so at that time we use structures which allows us to create our own data-type

// creating our structure
struct Date {
    int day;
    int month;
    int year;
};

void data(Date& date){
    cout<<"Enter day: ";
    cin>>date.day;
    cout<<"Enter month: ";
    cin>>date.month;
    cout<<"Enter year: ";
    cin>>date.year;
}

void display(Date date){
    cout<<"Today's date is: "<<date.day<<"/"<<date.month<<"/"<<date.year;
}

void readData(){
    
}

int main()
{
    // creating a datatype (user defined datatype)
    Date today = {20, 3, 2024};
    cout<<sizeof(today)<<endl;
    // read data
    data(today);
    display(today);
    
    return 0;
}