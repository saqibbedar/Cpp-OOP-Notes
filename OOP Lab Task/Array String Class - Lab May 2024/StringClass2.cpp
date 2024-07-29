#include <iostream>
#include <string>
#include <ostream>
#include <cstring>
#include <windows.h>
using namespace std;

class str{
    string value;
    friend ostream& operator<< (ostream&, const str&);
    public: 
    str(string value = "Null"){
        this->value = value; 
    }

    str operator+(const str &st){
        return (this->value + st.value);
    }
    bool operator==(const str &st){
        if(this->value == st.value){
            return true;
        }
        else{
            return false;
        }
        
        // tolower(value);
        // tolower(st.value);

    //     bool flag = false;
        
    //     for(int i=0; i != st.value[i]; i++){
    //         if(value[i] == st.value[i]){
    //             flag = true;
    //         }
    //         else{
    //             flag = false;
    //         }
    //     }
    //     if(flag){
    //         cout<<"Equal"<<endl;
    //     }else{
    //         cout<<"Not equal"<<endl;
    //     }

    // }
    // void show(str st){
    //     cout<<st.value<<endl;
    }
};




ostream& operator<<(ostream& out, const str &st){
    out<<st.value;
    return out;
}

int main()
{
    str st("Saqib,");
    str mySt("Bedar");
    str newSt = st + mySt;
    cout<<newSt<<endl;

    cout<<"Please wait";
    for(int i=0; i<4; i++){
        cout<<".";
        Sleep(400);
    }

    str name("Saqib  Bedar");
    str newName("Saqib Bedar");
    cout<<endl;
    name == newName ? cout<<"Equal"<<endl: cout<<"Not equal"<<endl;
    
    return 0;
}