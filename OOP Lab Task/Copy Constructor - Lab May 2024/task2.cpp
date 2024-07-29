#include <iostream>
using namespace std;

class abc{
    public:
    abc &f1(){
        cout<<"f1 function is called "<<&f1<<endl;
        // return *this;
    }
    abc &f2(){
        cout<<"f2 function is called "<<&f2<<endl;
        // return *this;
    }
    abc &f3(){
        cout<<"f3 function is called "<<&f3<<endl;
        // return *this;
    }
};

int main()
{
    abc obj;
    obj.f1();
    obj.f2();
    obj.f3();
    cout<<"\n             "<<endl;
    obj.f1().f2().f3();
    cout<<endl<<&obj<<endl;
    return 0;
}