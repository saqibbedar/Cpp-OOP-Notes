#include <iostream>
using namespace std;

class _Static{
    static int count;

    public:
    _Static(){
        count = 0;
    }
    ~_Static(){
        count++;
        cout<<"Count value is: "<<count<<endl;
        cout<<"Destructor"<<endl;
    }
    void display() const{
        cout<<"Count value is: "<<count<<endl;
        count+= 2;
    }
    static int getCount(){
        return count;
    }
};

int _Static::count = 10;

int main()
{
    _Static a;
    a.display();
    cout<<"Count value: "<<a.getCount()<<endl;

    return 0;
}