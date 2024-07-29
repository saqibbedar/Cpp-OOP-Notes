#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
private:
    string username;
    string password;

public:
    // Constructors
    User() {}
    User(const string& username, const string& password) : username(username), password(password) {}
    User(const User& other) : username(other.username), password(other.password) {}

    // Destructor
    ~User() {}

    // Getter methods
    string getUsername() const { return username; }
    string getPassword() const { return password; }

    // Setter methods
    void setUsername(const string& username) { this->username = username; }
    void setPassword(const string& password) { this->password = password; }

    // Overload input/output operators
    friend ostream& operator<<(ostream& os, const User& user) {
        os << user.username << "," << user.password;
        return os;
    }

    friend istream& operator>>(istream& is, User& user) {
        cout << "Enter Username: ";
        is >> user.username;
        cout << "Enter Password: ";
        is >> user.password;
        return is;
    }
};

void createUser(const User& user) {
    ofstream file("users.xlsx", ios::app); // Append mode
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }
    file << user << endl;
    file.close();
}

void readUsers() {
    ifstream file("users.xlsx");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void updateUser(const string& oldUsername, const string& newUsername, const string& newPassword) {
    ifstream inFile("users.xlsx");
    ofstream outFile("temp.xlsx");

    string line;
    while (getline(inFile, line)) {
        size_t pos = line.find(oldUsername);
        if (pos != string::npos) {
            line.replace(pos, oldUsername.length(), newUsername + "," + newPassword);
        }
        outFile << line << endl;
    }
    inFile.close();
    outFile.close();

    remove("users.xlsx");
    rename("temp.xlsx", "users.xlsx");
}

void deleteUser(const string& username) {
    ifstream inFile("users.xlsx");
    ofstream outFile("temp.xlsx");

    string line;
    while (getline(inFile, line)) {
        if (line.find(username) == string::npos) {
            outFile << line << endl;
        }
    }
    inFile.close();
    outFile.close();

    remove("users.xlsx");
    rename("temp.xlsx", "users.xlsx");
}

int main() {
    User user;
    char choice;

    do {
        cout << "1. Create User\n";
        cout << "2. Read Users\n";
        cout << "3. Update User\n";
        cout << "4. Delete User\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cin >> user;
                createUser(user);
                break;
            case '2':
                readUsers();
                break;
            case '3':
                {string oldUsername, newUsername, newPassword;
                cout << "Enter old username: ";
                cin >> oldUsername;
                cout << "Enter new username: ";
                cin >> newUsername;
                cout << "Enter new password: ";
                cin >> newPassword;
                updateUser(oldUsername, newUsername, newPassword);
                break;}
            case '4':
                {string delUsername;
                cout << "Enter username to delete: ";
                cin >> delUsername;
                deleteUser(delUsername);
                break;}
            case '5':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != '5');

    return 0;
}
