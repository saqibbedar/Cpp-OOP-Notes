#include "revStr.h"

void revStr(string& str){
    int size = str.length();
    for(int i=0; i < (size/2); i++){
        char temp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = temp;
    }
}
