// a. Write output of the above code segment
// b. write output of the above code segment after removing all virtual keywords

#include <iostream>
using namespace std;

class A{
    public:
    A(){cout<<"A"<<endl;}
    ~A(){cout<<"~A"<<endl;}
};

class B{
    A a;
    public:
    B(){cout<<"B"<<endl;}
    ~B(){cout<<"~B"<<endl;}
};

class C: virtual public B{
    public:
    C(){cout<<"C"<<endl;}
    ~C(){cout<<"~C"<<endl;}
};

class D: virtual public B{
    public:
    D(){cout<<"D"<<endl;}
    ~D(){cout<<"~D"<<endl;}
};

class E : public C, public D{
    public:
    E(){cout<<"E"<<endl;}
    ~E(){cout<<"~E"<<endl;}
};

int main()
{
    E e;
    return 0;
}

/*
output:
      A
      B
      C
      D
      E
      ~E
      ~D
      ~C
      ~B
      ~A
*/