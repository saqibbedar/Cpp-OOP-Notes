/*
    create Online_Bank_Account class with following data members:

    customer_name, cnic(constains 11 digits of user cnic without '-' symbol), account_number, user_id, user_password, secret_question, secret_answer, account_balance all others are string objects so they represent composite objects as data members of container class Online_Bank_Account. You can use string library.

    Provide parameterized constructor with parameters for name, cnic, id, and password. Inside the parameterized constructor, generate account number by taking first 2 letters of the username and all cnic digits and a last character representing a single digit 0-9 so the account number consist of 14 characters. Use proper string functions/operators to generate account number.

    Provide Forgot_Password(), change_sec_Question(), deposit_account(), withdraw_account() functions. Forgot_Password() is a boolean valued function. It will ask secret question and if the user enters correct answer, it will ask for a new password, repeat new password and if the new password and repeat password are same, it will change the previous password and return true. If password could not be changed, it will return false. Remember password is case sensitive but secret question and its answer are NOT case sensitive. 

    change_sec question will take a parameter for secret question and will change it according to parameter and will then will ask the user to enter secret_answer and will call change_secret_answer by passing this info as parameter to set the new answer. deposit_amount will take amount as parameter and add it to current balance. withdraw_amount will take amount as parameter and subtract it from balance.

    Implement the above functions of the class and handle the following errors/exceptions by implementing respective exception classes:

    NegativeAmountException - throw this exception if a negative amount is used for deposit.
    InsufficientFundsException - throw this exception fi the withdrawal amount is greater than the account balance.

    write a main() function in which create Online_Bank_Account object using parameterized constructor. Call different functions and test exceptions by calling deposit and withdraw functions with invalid values and catch the exceptions thrown by these functions.

*/ 


#include <iostream>
#include <string>
#include <cstdlib> // for random numbers
#include <stdexcept> // for exception handling

using namespace std;

class NegativeAmountException : public exception {
public:
    const char* what() const noexcept override {
        return "Negative amount is not allowed.";
    }
};

class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds for withdrawal.";
    }
};

class Online_Bank_Account {
private:
    string customer_name;
    string cnic;
    string account_number;
    string user_id;
    string user_password;
    string secret_question;
    string secret_answer;
    double account_balance;

    string generateAccountNumber(const string& name, const string& cnic) {
        string account_num = name.substr(0, 2) + cnic; // substr(position, length)
        account_num += to_string(rand() % 10); // rand() return single character b/w 1-9 and then converted to string
        return account_num;
    }

public:
    Online_Bank_Account(const string& name, const string& cnic, const string& id, const string& password)
        : customer_name(name), cnic(cnic), user_id(id), user_password(password), account_balance(0.0) {
        account_number = generateAccountNumber(name, cnic);
    }

    bool Forgot_Password() {
        string answer;
        cout << "Secret Question: " << secret_question << endl;
        cout << "Enter answer: ";
        cin.ignore();
        getline(cin, answer);

        // Convert both strings to lowercase for comparison
        string answer_lower = answer; // making copy of answer to perform operations on copy
        string secret_answer_lower = secret_answer; 

        for (char& c : answer_lower) c = tolower(c);
        for (char& c : secret_answer_lower) c = tolower(c);

        if (answer_lower == secret_answer_lower) {
            string new_password, repeat_password;
            cout << "Enter new password: ";
            getline(cin, new_password);
            cout << "Repeat new password: ";
            getline(cin, repeat_password);

            if (new_password == repeat_password) {
                user_password = new_password;
                return true;
            }
        }
        return false;
    }

    void change_secret_question(const string& question) {
        secret_question = question;
        cout << "Enter new secret answer: ";
        cin.ignore();
        getline(cin, secret_answer);
    }

    void deposit_account(double amount) {
        if (amount < 0) {
            throw NegativeAmountException();
        }
        account_balance += amount;
    }

    void withdraw_account(double amount) {
        if (amount > account_balance) {
            throw InsufficientFundsException();
        }
        account_balance -= amount;
    }

    double get_balance() const {
        return account_balance;
    }
};

int main() {
    try {
        Online_Bank_Account account("Saqib Bedar", "12345678901", "saqib", "pass123");

        account.change_secret_question("What is your favorite color?");
        
        cout << "Attempting to deposit -50.0" << endl;
        account.deposit_account(-50.0); // This should throw an exception
    } catch (const NegativeAmountException& e) {
        cerr << e.what() << endl;
    }

    try {
        Online_Bank_Account account("Mudasir", "10987654321", "m123", "securePass!");

        cout << "Depositing 100.0" << endl;
        account.deposit_account(100.0);
        cout << "Current balance: " << account.get_balance() << endl;

        cout << "Attempting to withdraw 150.0" << endl;
        account.withdraw_account(150.0); // This should throw an exception
    } catch (const InsufficientFundsException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
