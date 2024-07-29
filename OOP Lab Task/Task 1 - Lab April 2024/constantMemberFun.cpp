#include <iostream>
using namespace std;

// const member functions : they can not be changed

class Date
{
    int day, month, year;

public:
    Date() : day(1), month(1), year(2000) {}
    Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy) {}

    void display() const
    {
        // day = 2; will through error
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main()
{
    Date d(2, 2, 2002);
    d.display();
    return 0;
}