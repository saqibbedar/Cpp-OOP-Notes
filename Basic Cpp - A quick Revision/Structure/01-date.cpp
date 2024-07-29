// structure: consecutive memory location, we sue array to hold multiple values at same time with same data-type, but what if we want values in different data types so there we use structures, to hold values in different data types.

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
    Date today = {12, 5, 2024};                                                           // 12 may, 2024
    cout << "Today is: " << today.day << "/" << today.month << "/" << today.year << endl; // 12/5/2024

    // assignment of whole structure is available, we can assign a structure to other
    Date d1 = today;
    cout << "d1 is = " << d1.day << "/" << d1.month << "/" << d1.year << endl; // 12/5/2024

    // but when working with pointer then we can't assign a structure to ohter because of difference in addresses i.e. deep copy and shallow copy

    // we can also get values from user
    cout << "what's day today? ";
    cin >> today.day;
    cout << "what's month today? ";
    cin >> today.month;
    cout << "what's year today? ";
    cin >> today.year;

    cout << "You entered date: ";
    cout << today.day << "/" << today.month << "/" << today.year << endl;

    return 0;
}
