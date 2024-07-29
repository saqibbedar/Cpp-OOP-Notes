#include <iostream>
using namespace std;

// first name space
namespace first_space
{
void func()
{
	cout << "Inside first_space" << endl;
}
}

namespace hello{
   class A {
      public:
      void display() const{
         cout<<"Hello, world!"<<endl;
      }
   };
}
// using namespace hello;

// second name space
namespace second_space
{
void func()
{
	cout << "Inside second_space" << endl;
}
}

namespace nested_namespace
{
  void func()
  {
     cout << "Inside nested_namespace" << endl;
  }
  // second name space
  namespace nested_second_space
  {
     void func()
     {
        cout << "Inside nested_second_space" << endl;
     }
  }
}

// using namespace first_space;
using namespace nested_namespace::nested_second_space;

int main ()
{

func(); // Inside nested_second_space
second_space::func(); // Inside second_space

// from hello space

hello::A a;
a.display(); // Hello, world!

return 0;
}
