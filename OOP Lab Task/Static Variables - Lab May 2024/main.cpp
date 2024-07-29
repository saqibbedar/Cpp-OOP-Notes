#include <iostream>
using namespace std;

// static variables don't have this keyword

class ABC
{
    private:
    int x;
    static int count;
    public:
    ABC()
    {
        count++;
    }
    ABC(int y)
    {
        x=y;
        count++;
    }
    void ftn()
    {
        cout<<"total = "<<count<<endl;
        // ftn2();
        // static int a = 1;
        // a++;
        // cout << a << endl;
    }
    // static void ftn2(){
        // ftn(); this will through error 
    //     cout<<"this is static method: "<<endl;
    // }
    // ~ABC(){
    //     a--;
    // }
};
int ABC :: count=0;

int main()
{
    ABC obj(1), obj2, obj3(2), obj4;
    ABC obj1;
    obj1.ftn();
    // // obj.ftn();
    // obj.ftn();

    // ABC::ftn2();
    // // ABC::ftn();
    return 0;
}