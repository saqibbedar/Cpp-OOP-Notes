#include "Rational.hpp"
#include <iostream>



using namespace std;

int main() {
    Rational r1(1, 2), r4, r5, r6, r7;
    cout << "r1 num: " << r1.getNum() <<" r1 denom: "<< r1.getDenom() << endl;

    Rational r2(12, 1);
    cout << "r2 num: " << r2.getNum() <<" r2 denom: "<< r2.getDenom() << endl;


    Rational r3 = r2;
    cout << "r3 num: " << r3.getNum() <<" r3 denom: "<< r3.getDenom() << endl;


    r3.setNum(5);
    r3.setDenom(1);
    cout<<"Updated r3\n";
    cout << "r3 num: " << r3.getNum() <<" r3 denom: "<< r3.getDenom() << endl;


    cout << "Addition of r1 and r2: ";
    r4 = r1 + r2;
    display(r4);

    // cout << "Subtraction of r1 and r2: ";
    // r5 = r1 - r2;
    // cout << r5 << endl;

    // cout << "Multiplication of r1 and r2: ";
    // r6 = r1 * r2;
    // cout << r6 << endl;

    // cout << "Division of r1 and r2: ";
    // r7 = r1 / r2;
    // cout << r7 << endl;

    // if (r1 > r2) {
    //     cout << "R1 is greater than R2." << endl;
    // }
    // else {
    //     cout << "R2 is greater than R1." << endl;
    // }

    // if (r1 != r2) {
    //     cout << "R1 is not equal to R2." << endl;
    // }
    // else {
    //     cout << "R1 is equal to R2." << endl;
    // }

    // r1--;
    // cout << "Updated r: " << r1 << endl;

    // int n, d;
    // n = r1;
    // d = r2;
    // cout << "n" << n << " " << "d" << d << endl;

    // cout << r1 << endl;
    return 0;
}
