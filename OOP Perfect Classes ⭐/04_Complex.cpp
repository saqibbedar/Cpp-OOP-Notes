/*
Consider class Complex, the class enables operations on so-called complex numbers. These are numbers of the form realPart + imaginaryPart * i, where i has the value sqrt(–1)
a) Modify the class to enable input and output of complex numbers via overloaded >> and
<< operators, respectively (you should remove the print function from the class).
b) Overload the multiplication operator to enable multiplication of two complex numbers
as in algebra.
c) Overload the == and != operators to allow comparisons of complex numbers.
*/

#include <iostream>
using namespace std;

class Complex
{
    double real, imag;
    friend ostream &operator<<(ostream &out, const Complex &other);
    friend istream &operator>>(istream &in, Complex &other);

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // The multiplication of two complex numbers is defined as:
    // (a+bi)×(c+di) = (ac−bd)+(ad+bc)i
    Complex operator*(const Complex &other) const
    {
        Complex result;
        result.real = real * other.real - imag * other.imag;
        result.imag = real * other.imag + imag * other.real;
        return result;
    }

    Complex operator+(const Complex& other){
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other){
        return Complex(real - other.real, imag - other.imag);
    }

    bool operator==(const Complex &other) const
    {
        return (real == other.real && imag == other.imag);
    }

    bool operator!=(const Complex &other) const
    {
        return !(*this == other);
    }

    void print() const{
        cout<<"("<<real<<", "<<imag<<"i)"<<endl;
    }
};

ostream &operator<<(ostream &out, const Complex &other)
{
    out << other.real << " + " << other.imag << "i";
    return out;
}
istream &operator>>(istream &in, Complex &other)
{
    cout << "Enter real number: ";
    in >> other.real;
    cout << "Enter imaginary number: ";
    in >> other.imag;
    return in;
}

int main()
{
    Complex c1, c2;

    cout << "Enter first complex number:" << endl;
    cin >> c1;
    cout << "Enter second complex number:" << endl;
    cin >> c2;

    c2.print();

    Complex result = c1 * c2;
    cout << "Multiplication result: " << result << endl;

    if (c1 == c2)
    {
        cout << "The complex numbers are equal." << endl;
    }
    else
    {
        cout << "The complex numbers are not equal." << endl;
    }

    return 0;
}