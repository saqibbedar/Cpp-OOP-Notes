#include <iostream>
using namespace std;

int strLength(char str[]){
    int i = 0;
    for(; str[i] != '\0'; i++);
    return i;
}

void revStr(char str[]){

    int size = strLength(str);

    for(int i=0; i < size/2; i++){
        char temp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = temp;
    }

}

int main()
{
    char text[] = "Saqib";
    revStr(text);

    cout<<text;

    return 0;
}
