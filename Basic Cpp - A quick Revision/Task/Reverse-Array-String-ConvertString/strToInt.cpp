// string to integer
#include <iostream>
using namespace std;

int strToInt(char str[]){
    int result = 0;
    for(int i= 0; str[i] != '\0'; i++){
        if(str[i] - '0' >= 0 && str[i] -'0' <= 9)
            result = result * 10 + str[i] - '0';
        else 
            return -1;
    }
    return result;
}



int main()
{
    char str[] = "3213";
    int n = strToInt(str);
    cout<<n;

    return 0;
}
