// #include <iostream>
// using namespace std;

// const int LIMIT = 10;

// class safeArray
// {

//     int *arr;

// public:
//     safeArray()
//     {
//         arr = new int[LIMIT];
//         for (int i = 0; i < LIMIT; i++)
//         {
//             arr[i] = i + 2;
//         }
//     }
//     int& getIndex(int index, int size, int value)
//     {
//         if (size <= LIMIT)
//         {
//             // return (arr[index] = value);
//             arr[index] = value;
//             cout<<arr[index]<<endl;
//         }
//         else
//         {
//             cout << "Unable to access the array" << endl;
//         }
//     }
// };

// int main()
// {
//     int arr[LIMIT] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
//     safeArray a;

//     a.getIndex(arr[5], LIMIT, 500);

//     return 0;
// }

#include <windows.h>
#include <iostream>
using namespace std;
const int LIMIT = 10;

class safeArray
{
    int *arr;

public:
    safeArray()
    {
        arr = new int[LIMIT];
        for (int i = 0; i < LIMIT; i++)
        {
            arr[i] = i + 2;
        }
    }
    /*int& getIndex(int index, int size, int value)
    {
        if (index < size)
        {
            arr[index] = value;
            cout << arr[index] << endl;
        }
        else
        {
            cout << "Unable to access the array" << endl;
        }
    }*/

    int& operator[](int index){
        if(index > 0 && index < LIMIT){
            return arr[index];
        }
        else{
            cout<<"Unable to access the array!"<<endl;
        }
    }
    void show(){
        cout<<"Array elements are: ";
        for(int i= 0; i<LIMIT; i++){
            cout<<arr[i]<<" ";
        }
    }
    ~safeArray(){
        delete[] arr;
    }
};

int main()
{
    safeArray a;

    // a.getIndex(5, LIMIT, 500); 

    a[5] = 10;
    cout<<a[5]<<endl;
    Sleep(1000);
    cout<<"\nPlease wait";
    for(int i=0; i<5; i++){
        cout<<".";
        Sleep(400);
    }
    system("cls");
    a.show();

    return 0;
}