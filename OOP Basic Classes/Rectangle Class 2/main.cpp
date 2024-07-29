

#include <iostream>
// #include"functionsdefined.cpp"
#include"rectangle.hpp"
using namespace std;

int main()
{
	rectangle r1;
	r1.setlength(10);
	r1.setlength(20);

	cout<<r1.getlength()<<endl;
	cout<<r1.getwidth()<<endl;
	/*r1.setboth(5, 10);
	cout << "Length and Width of R1:";
	cout << r1.getlength()<<"\t" << r1.getwidth();
	
	cout << endl;
	cout << "Length and Width of R2:";
	cout << r2.getlength()<<"\t"<< r2.getwidth();
	cout << endl;
	cout << "Parameter of R1:";
	cout << r1.getparameter();
	cout << endl;
	cout << "Parameter of R2:" ;
	cout << r2.getparameter();
	*/
	return 0;
}
