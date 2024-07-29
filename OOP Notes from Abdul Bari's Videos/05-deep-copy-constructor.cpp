#include <iostream>
using namespace std;

class Test
{
    int a, *ptr;

public:
    Test(int x)
    {
        a = x;
        ptr = new int[a];
    }

    // copy constructor: if dynamic memory has been allocated by an object then copy constructor may not create a new memory for it, so we are suppose to be careful while dealing with dynamic memory allocation.

    // this way is wrong
    // Test(Test &t){
    //     a = t.a;
    //     ptr = t.ptr; // will point to same array that has assigned to ptr earlier
    // }

    // correct way for copying a an object properly
    Test(Test &t)
    {
        a = t.a;
        ptr = new int[a]; // now a new array would be assigned and ptr will point to new array not earlier created, so this is the deep copy constructor
        for(int i=0; i<a; i++){
            ptr[i] = t.ptr[i];
        }
    }
    ~Test()
    {
        delete[] ptr;
    }

    void setValues()
    {
        for (int i = 0; i < a; i++)
        {
            cout << "Enter value for index " << i << ": ";
            cin >> ptr[i];
        }
    }

    void printValues()
    {
        for (int i = 0; i < a; i++)
        {
            cout << "Value at index " << i << ": " << ptr[i] << endl;
        }
    }
};
int main()
{
    Test t(5);
    t.setValues();
    t.printValues();

    Test t2 = t;
    t2.printValues();

    return 0;
}