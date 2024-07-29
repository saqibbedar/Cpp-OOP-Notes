#include <iostream>
#include <fstream>
#include <cstring> // using for comparing 
using namespace std;

// Declaring necessary global variables
const int MAX = 10; // for managing size at one place
// for dob year
const int MaxYear = 2008; 
const int MinYear = 1950;

// creating structures
struct Date
{
    int day;
    int month;
    int year;
};
struct Student{
    char regNo[10]; 
    char name[45];
    Date dob;
    int marks[5];
};

// input marks
void input_marks(Student *st, int i);

// display marks
void display_marks(Student *st, int size);

// display menu
void displayMenu();

// Handle options 
char optionHandler(char);

// date of birth handler
void handle_dob(Student*, int);

// display founded record
void display_founded_Record(Student *st, int index);

// insert record
void insert(Student*, int, int&);

// main find function to find record based on regNo
int isFound(Student *st, const char *check_regNo, int size);

// find function for option f & F
void find(Student *st, int size);

// delete Record
void deleteRecord(Student *st, int &size);

// modify
void modify(Student *st, int size);

// print
void printRecord(Student *st, int size);

// quit
void quit(Student *st, int size);

// Handle cases
void casesHandler(Student *st, int currSize, int MAX, char option);

int main()
{
    // Part 1 - commented

    /*

    // Part-1 create binaryData file -- "Student.dat"
    ofstream write("Student.dat", ios::binary);

    // create a array of Students of size 5
    const int SIZE = 5; // for writing size in binary file
    Student st[SIZE]; 

    // Read array
    for(int i= 0; i<5; i++){
        cout<<"What's reg number? ";
        cin>>st[i].regNo;
        cin.ignore();
        cout<<"What's name? ";
        cin.getline(st[i].name, 45);
        cout<<"What's date of birth? (Date format Y/M/D)\n";
        handle_dob(st, i);
        input_marks(st, i);
    }
    
    write.write((char*)&SIZE, sizeof(int)); // write the SIZE in binary file

    for(int i=0; i<5; i++){
        write.write((char*)&st[i], sizeof(Student)); // write 
    }
    write.close(); // close file

    */
    
    // Part -2 - create student of size 10
    Student st[MAX]; // max is defined as global variable

    int currSize; // current size of array
    ifstream read("Student.dat", ios::binary);
    read.read((char*)&currSize, sizeof(int)); // current first elem
    // cout<<currSize; // testing result

    // Read whole Student data from binary file
    for(int i=0; i< currSize; i++){
        read.read((char*)&st[i], sizeof(Student));
    }

    cout<<currSize;

    // display menu
    displayMenu();
    // read option
    char option;
    // check option and use functions accordingly
    casesHandler(st, currSize, MAX, option);

    read.close();
    return 0;
}

// Input marks
void input_marks(Student *st, int i){
    for(int j=0; j<5; j++){
        while (true)
            {
                cout<<"What's marks of your subject "<<j+1<<" : ";
                cin>>st[i].marks[j];
                if(st[i].marks[j] < 0 || st[i].marks[j] > 100){
                    cout<<"*** Invalid marks! Please enter between 0-100 ***\n";
                }
                else{
                    break;
                }
            }
        }

}

// display marks
void display_marks(Student *st, int i){
        for(int j=0; j<5; j++){
            cout<<"Subject "<<j+1<<" : "<<st[i].marks[j]<<endl;
        }
}

// display founded record
void display_founded_Record(Student *st, int index){
    cout<<"\n             Student Data            "<<endl;
        cout<<"*************************************"<<endl;
        cout<<"RegNo: "<<st[index].regNo<<endl;
        cout<<"Name: "<<st[index].name<<endl;
        cout<<"DOB: "<<st[index].dob.day<<"/"<<st[index].dob.month<<"/"<<st[index].dob.year<<endl;
        display_marks(st, index);
}

// Handle options
char optionHandler(char option){
    cin>>option;
    return option;
}

// main function for finding record based on regNo
int isFound(Student *st, const char *check_regNo, int size){
    for(int i=0; i<size; i++){
        if(strcmp(check_regNo, st[i].regNo) == 0){
            return i;
        }
    }
    return -1;
}

// Handle date of birth
void handle_dob(Student *st, int index){
    
        // handle year 
        do{
            cout<<"What's year? ";
            cin>>st[index].dob.year;
        }while(st[index].dob.year <= MinYear || st[index].dob.year > MaxYear);

        // handle month
        do{
            cout<<"What's month? ";
            cin>>st[index].dob.month;
        }while(st[index].dob.month <= 0 || st[index].dob.month > 12);

        // handle days
        switch (st[index].dob.month)
            {
            case 2:
                do{
                cout<<"What's day? ";
                cin>>st[index].dob.day;
                }while(st[index].dob.day <= 0 || st[index].dob.day > 28);
                break;
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                do{
                cout<<"What's day? ";
                cin>>st[index].dob.day;
                }while(st[index].dob.day <= 0 || st[index].dob.day > 31);
                break;
            case 4: case 6: case 9: case 11:
                do{
                cout<<"What's day? ";
                cin>>st[index].dob.day;
                }while(st[index].dob.day <= 0 || st[index].dob.day > 30);
                break;
            }
    }

// handle menu
void displayMenu(){
    cout<<"\n             Student Data            "<<endl;
    cout<<"*************************************"<<endl;
    cout<<"Insert             :            [I/i]"<<endl;
    cout<<"Delete             :            [D/d]"<<endl;
    cout<<"Modify             :            [M/m]"<<endl;
    cout<<"Find               :            [F/f]"<<endl;
    cout<<"Print              :            [P/p]"<<endl;
    cout<<"Quit               :            [Q/q]"<<endl;
    cout<<"Enter Option       :              ";
}

// handle cases
void casesHandler(Student *st, int currSize, int MAX, char option){
    switch (optionHandler(option))
    {
    case 'I': case 'i':
        insert(st, MAX, currSize);
        break;
    case 'D': case 'd':
        deleteRecord(st, currSize);
        break;
    case 'M': case 'm':
        modify(st, currSize);
        break;
    case 'F': case 'f':
        find(st, currSize);
        break;
    case 'P': case 'p':
        printRecord(st, currSize);
        break;
    case 'Q': case 'q':
        quit(st, currSize);
        break;
    }
}

// print record
void printRecord(Student *st, int size){
    for(int i = 0; i<size; i++){
        cout<<"\n             Student Data            "<<endl;
        cout<<"*************************************"<<endl;
        cout<<"RegNo: "<<st[i].regNo<<endl;
        cout<<"Name: "<<st[i].name<<endl;
        cout<<"DOB: "<<st[i].dob.day<<"/"<<st[i].dob.month<<"/"<<st[i].dob.year<<endl;
        display_marks(st, i);
    }
    cout<<"\nDo you want to perform another operation? If not press Q/q to quit program\n";
        displayMenu(); // display the menu
        char option; // for more options
        casesHandler(st, size, MAX, option); // handle cases
}

// insert record
void insert(Student *st, int Max, int& currSize){
    // check if room is free!
    if(currSize != Max){
        // get index between 0 and currSize
        int index;
        do
        {
            cout<<"Enter the index between 0 and " <<currSize <<" : ";
            cin>>index;
        } while (index < 0 || index > currSize);
        
        // shifting rooms
        for(int i = currSize; i>= index; i--){
            st[i+1] = st[i];
        }

        // After insertion current size will be incremented
        currSize++;

        // read the data finally
        cout<<"What's reg number? ";
        cin>>st[index].regNo;
        cin.ignore();
        cout<<"What's name? ";
        cin.getline(st[index].name, 45);
        cout<<"What's date of birth? (Date format Y/M/D):"<<endl;
        handle_dob(st, index); // date of birth handler
        input_marks(st, index); // read marks

        cout<<"\nData entered successfully! do you want to perform any other operation? If not please press Q/q to quit."<<endl;

        displayMenu(); // display the menu
        char option; // for more options
        casesHandler(st, currSize, MAX, option); // handle cases

    }else{
        cout<<"Sorry! there is no room available to insert the data."<<endl;
    }
}

// delete Record
void deleteRecord(Student *st, int &size){
    char check_regNo[10]; 
    cout<<"\nWhat's registration number? ";
    cin>>check_regNo;

    int index = isFound(st, check_regNo, size);
    if(index != -1){
        for(int i=index; i<size; i++){
            st[i] = st[i + 1];
        }
        size--;
        cout<<"\nOperation successful! do you want to perform any other operation? If not please press Q/q to quit.\n";
        displayMenu(); // display the menu
        char option; // for more options
        casesHandler(st, size, MAX, option); // handle cases
    } else {
        cout<<"No data matched! try re-run program."<<endl;
    }
}

// find function for option f & F
void find(Student *st, int size){
    char check_regNo[10];
    cout<<"\nWhat's registration number? ";
    cin>>check_regNo;
    int index = isFound(st, check_regNo, size);
    if(index != -1){

        // print the founded record
        display_founded_Record(st, index);

        cout<<"\nDo you want to perform another operation? If not press Q/q to quit program\n";
        displayMenu(); // display the menu
        char option; // for more options
        casesHandler(st, size, MAX, option); // handle cases
    } else {
        cout<<"No data matched! try re-run program."<<endl;
    }
}

// modify record
void modify(Student *st, int size){
    char check_regNo[10]; 
    cout<<"\nWhat's registration number? ";
    cin>>check_regNo;
    int index = isFound(st, check_regNo, size);
    if(index != -1){
        
        // display the founded record
        display_founded_Record(st, index);

        while(true){
            char option;
            do{
                cout<<"Want to modify Data? (y/n): ";
                cin>>option;
            }while(option != 'y' && option != 'n');

            if(option == 'y'){
                cout<<"\n  which Data you want to modify?"<<endl;
                cout<<"\n            Your Data            "<<endl;
                cout<<"*********************************"<<endl;
                cout<<"RegNo.          :           [R/r]"<<endl;
                cout<<"Name            :           [N/n]"<<endl;
                cout<<"DOB             :           [D/d]"<<endl;
                cout<<"Marks           :           [M/m]"<<endl;
                cout<<"Enter Option    :             ";

                cin>>option; // get option

                // handle options
                switch (option)
                {
                case 'R': case 'r':
                    cout<<"What's regNo? ";
                    cin>>st[index].regNo;
                    break;
                case 'N': case 'n':
                    cout<<"What's name? ";
                    cin.ignore();
                    cin.getline(st[index].name, 40);
                    break;
                case 'D': case 'd':
                    cout<<"What's date of birth? (Date format Y/M/D)\n";
                    handle_dob(st, index); // handle dob
                    break;
                case 'M': case 'm':
                    int marksOption;
                    do{
                        cout<<"\nWhich subject marks you want to modify? Subjects(1, 2, 3, 4, 5)"<<endl;
                        cout<<"\nEnter option: ";
                        cin>>marksOption;
                        switch (marksOption)
                        {
                        case 1:
                            cin>>st[index].marks[0];  
                            break;
                        case 2:
                            cin>>st[index].marks[1];  
                            break;
                        case 3:
                            cin>>st[index].marks[2];  
                            break;
                        case 4:
                            cin>>st[index].marks[3];  
                            break;
                        case 5:
                            cin>>st[index].marks[4];  
                            break;
                        }
                    }while(marksOption <= 0 || marksOption > 5);
                    break;
                } 
                
                break; // break the loop
            }
            if(option == 'n'){
                cout<<"\nProgram ended successfully!\n";
                quit(st, size);
                break;
            }
        }
        
        cout<<"\nOperation successful! do you want to perform any other operation? If not please press Q/q to quit.\n";
        displayMenu(); // display the menu
        char option; // for more options
        casesHandler(st, size, MAX, option); // handle cases
    } else {
        cout<<"No data matched! try re-run program."<<endl;
    }
}

// quit 
void quit(Student *st, int size){

    ofstream write("Student.dat", ios::binary);
    write.write((char*)&size, sizeof(int)); // write the SIZE in binary file

    // Writing to the file
    for(int i=0; i<size; i++){
        write.write((char*)&st[i], sizeof(Student)); 
    }

    write.close(); // close file
}
