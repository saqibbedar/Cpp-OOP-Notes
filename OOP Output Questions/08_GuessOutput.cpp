/*
Defined below are two simple classes, TwoD and ThreeD, Identify two problems with the ThreeD class. You must explain the problem and provide a solution to what the programmer intended.

class TwoD ( // base class

private:

double x, y

public:

TwoD (double xx, double yy)x(xx), y (yy) () double sumsqr() (return x*x+y*y; )

class ThreeD public TwoD ( // derived class

private: double z

ThreeD (double xx, double yy, double zz) {

public:

TwoD (xx, yy):

double sumsqr() (return x*x+y*y*z*z);

};
*/

/*

Problem 1: Incorrect Member Initialization Order
Problem: The initialization of the base class TwoD and the member z in the derived class ThreeD is incorrect in the constructor's initialization list. The TwoD constructor should be called in the initialization list before initializing z.

Solution: Ensure that the base class TwoD is properly initialized in the initializer list of the derived class ThreeD constructor before initializing z.

Problem 2: Access to Private Members of Base Class
Problem: The sumsqr method in ThreeD tries to directly access the private members x and y of the base class TwoD. In C++, private members of the base class are not accessible directly by the derived class.

Solution: Use the public methods of the base class to access x and y or make them protected instead of private in the base class if direct access is needed. Here, a getter method for sumsqr in the base class is already provided.

*/

#include <iostream>
using namespace std;

class TwoD {
private:
    double x, y;

public:
    TwoD(double xx, double yy) : x(xx), y(yy) {}

    double sumsqr() const {
        return x * x + y * y;
    }

protected:
    double getX() const { return x; }
    double getY() const { return y; }
};

class ThreeD : public TwoD {
private:
    double z;

public:
    ThreeD(double xx, double yy, double zz) : TwoD(xx, yy), z(zz) {}

    double sumsqr() const {
        return getX() * getX() + getY() * getY() + z * z;
    }
};

int main() {
    TwoD twoD(3.0, 4.0);
    cout << "TwoD sumsqr: " << twoD.sumsqr() << endl;

    ThreeD threeD(3.0, 4.0, 5.0);
    cout << "ThreeD sumsqr: " << threeD.sumsqr() << endl;

    return 0;
}

/*
output:
    TwoD sumsqr: 25
    ThreeD sumsqr: 50
*/