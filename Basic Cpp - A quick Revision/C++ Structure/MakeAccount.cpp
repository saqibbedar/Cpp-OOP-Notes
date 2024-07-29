#include <iostream>
#include <string>
using namespace std;

struct Account{
    // char accNum[9];
    char accNo[9];
    double balance;
    double iRate; 
    double avgMonthlyBal;

    Account(){
        // accNum[9] = {'A','C', 'Z', '4', '2', '1', '3', '7' '\0'};
        accNo[9] = '\0';
        // accNo = "ACZ42137";
        balance = 4512.59;
        iRate = 4.0/ 100;
        avgMonthlyBal = 4217.07;
    }

};

int main()
{
    Account p1;
    cin>>p1.accNo;
    cin>>p1.balance;
    cin>>p1.iRate;
    cin>>p1.avgMonthlyBal;
    cout<<"Account Number: "<<p1.accNo<<endl;
    cout<<"Account Balance: "<<p1.balance<<endl;
    cout<<"InterestRate: "<<p1.iRate<<endl;
    cout<<"Avg. Monthly Balance: "<<p1.avgMonthlyBal<<endl;

    return 0;
}