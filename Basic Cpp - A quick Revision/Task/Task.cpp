#include <iostream>
using namespace std;

// toUpperCase
char* toUpperCase(char str[]) {

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
    }
    }

    return str;
}

// toLowerCase
char* toLowerCase(char str[]){

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
    }
    return str;
}

// compare strings
bool strComp(char str1[], char str2[]){
    
    // ignore cases
    toLowerCase(str1); 
    toLowerCase(str2);

    for(int i = 0; str1[i] != '\0'; i++){
        if(str1[i] == str2[i])
            return true;
    } 

    return false;
}

// check alphabet
bool isAlpha(char *str){
    toLowerCase(str); // ignore the case
    for(int i = 0; str[i] != '\0'; i++){
        if(!(str[i] >= 'a' && str[i] <= 'z'))
            return false;
    }
    return true;
}

// check digit
bool isDigit(char digit){
    if(digit >= '0' && digit <= '9')
        return true;
    else
        return false;
}

// check white space
bool isSpace(char space){
    if(space == ' ')
        return true;
    else 
        return false;
}

// isUpper
bool isUpper(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if(!(str[i] >= 'A' && str[i] <= 'Z'))
            return false;
    }
    return true;
}

bool isLower(char str[]){
    for(int i= 0; str[i] != '\0'; i++){
        if(!(str[i] >= 'a' && str[i] <= 'z'))
            return 0;
    }
    return 1;
}

// isAlpha or isDigit
bool isAlNum(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        if(!(isAlpha(&str[i])) && !(isDigit(str[i])))
            return 0;
    }
    return 1;
}

int main()
{
    char str1[] = "hello";

    // Upper and lower case
    cout<<"hello = "<<toUpperCase(str1)<<" (toUpperCase)"<<endl;
    cout<<"HELLO = "<<toLowerCase(str1)<<" (toLowerCase)"<<endl;
    
    char str2[] = "HeLLO";

    // compare strings
    strComp(str1, str2) ? cout<<"String is Equal"<<endl : cout<<"String is not equal"<<endl;

    // isDigit
    isDigit('3') ? cout<<"isDigit? True"<<endl : cout<<"isDigit? False"<<endl;

    // isAlpha
    isAlpha(str2) ? cout<<"isAlpha? True"<<endl : cout<<"isAlpha? False"<<endl;

    // isSpace
    isSpace(' ') ? cout<<"isSpace? True"<<endl : cout<<"isSpace? False"<<endl;

    // isUpper
    char str3[] = "HELLO";
    isUpper(str3) ? cout<<"isUpper? True"<<endl : cout<<"isUpper? False";

    // isLower
    char str4[] = "hello";
    isLower(str4) ? cout<<"isLower? True"<<endl : cout<<"isLower? False"<<endl;

    // isalnum?
    char str5[] = "123";
    isAlNum(str5) ? cout<<"isAlNum? True"<<endl : cout<<"isAlNum? False"<<endl;

    return 0;
}