#include<iostream>
using namespace std;
class A{
    public:
    A(int a=0)
    {
        cout<<a<<"A\n";
    }

};
class B:public A{
public:
B(int b=0):A(b-1)
{
cout<<b<<"B\n";
}
};
class C:public A{
    private:
    B datamember;
public:
C(int c=0): A(c-1)
{
    cout<<c<<"C\n";
}

};
class test:public C,public B{
    C state;
    public:
    test():state(10),B(40),C(50)
    {
        cout<<"test\n";
    }
};
int main()
{
    test me;
    cout<<"done";
}

/*
49A
-1A
0B
50C
39A
40B
9A
-1A
0B
10C
test
done
*/