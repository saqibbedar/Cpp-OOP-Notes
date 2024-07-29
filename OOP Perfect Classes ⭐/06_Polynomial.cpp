/*

Develop class Polynomial. The internal representation of a Polynomial
is an array of terms. Each term contains a coefficient and an exponent, e.g., the term
2x^4 has the coefficient 2 and the exponent 4. Develop a complete class containing proper constructor and destructor functions as well as set and get functions. The class should also provide the following

overloaded operator capabilities:
a) Overload the addition operator (+) to add two Polynomials.
b) Overload the subtraction operator (-) to subtract two Polynomials.
c) Overload the assignment operator to assign one Polynomial to another.
d) Overload the multiplication operator (*) to multiply two Polynomials.
e) Overload the addition assignment operator (+=), subtraction assignment operator (-=),
and multiplication assignment operator (*=).

*/

#include <iostream>
#include <string>
using namespace std;

// for handling error
class Error {
    string msg;
public:
    explicit Error(const string m = "~Unknown") : msg(m) {}
    void showError() const {
        cerr << "Error: " << msg << endl;
    }
};

class Term {
public:
    int coefficient, exponent;
    Term(int c = 0, int e = 0) : coefficient(c), exponent(e) {};
};

class Polynomial {
    Term* terms;
    int capacity; // terms capacity
    int size; // no. of terms

    void resize(int new_capacity) {
        Term* newTerms = new Term[new_capacity];
        for (int i = 0; i < size; i++) {
            newTerms[i] = terms[i];
        }
        delete[] terms;
        terms = newTerms;
        capacity = new_capacity;
    }

    friend ostream& operator<<(ostream&, const Polynomial&);
    friend istream& operator>>(istream&, Polynomial&);

public:

    Polynomial(int initialCapacity = 5) 
    : capacity(initialCapacity), size(0)
    {
        terms = new Term[capacity];
    }

    Polynomial(const Polynomial& other) :
        capacity(other.capacity), size(other.size)
    {
        terms = new Term[capacity];
        for (int i = 0; i < size; i++) {
            terms[i] = other.terms[i];
        }
    }

    ~Polynomial(){
        delete[] terms;
    }
    
    void setTerm(int index, int coff, int exp) {
        if (index >= 0 && index < size) {
            terms[index].coefficient = coff;
            terms[index].exponent = exp;
        }
        else throw Error("Index out of range.");
    }

    Term getTerm(int index) const {
        if (index >= 0 && index < size) {
            return terms[index];
        }
        else throw Error("Index out of range.");
    }

    int getSize() const {
        return size;
    }

    void addTerm(int coff, int exp) {
        for (int i = 0; i < size; i++) {
            if (terms[i].exponent == exp) {
                terms[i].coefficient += coff;
                if (terms[i].coefficient == 0) {
                    for (int j = i; j < size - 1; j++) {
                        terms[j] = terms[j + 1];
                    }
                    --size;
                }
                return;
            }
        }
        if (size == capacity) { // if array is full then double its capacity
            resize(2 * capacity);
        }
        terms[size++] = Term(coff, exp); // add new term to array at index size++
    }

    Polynomial operator+(const Polynomial& other) {
        Polynomial result(capacity + other.capacity);
        for (int i = 0; i < size; i++) {
            result.addTerm(terms[i].coefficient, terms[i].exponent);
        }
        for (int i = 0; i < other.size; i++) {
            result.addTerm(other.terms[i].coefficient, other.terms[i].exponent);
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) {
        Polynomial result(capacity + other.capacity);
        for (int i = 0; i < size; i++) {
            result.addTerm(terms[i].coefficient, terms[i].exponent);
        }
        for (int i = 0; i < other.size; i++) {
            result.addTerm(-other.terms[i].coefficient, other.terms[i].exponent);
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) {
        Polynomial result(capacity + other.capacity);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < other.size; j++) {
                result.addTerm(terms[i].coefficient * other.terms[j].coefficient,
                    terms[i].exponent + other.terms[j].exponent
                );
            }
        }
        return result;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            if (terms != nullptr) {
                delete[] terms;
            }
            size = other.size;
            capacity = other.capacity;
            terms = new Term[capacity];
            for (int i = 0; i < size; i++) {
                terms[i] = other.terms[i];
            }
        }
        return *this;
    }

    Polynomial& operator+=(const Polynomial& other) {
        for (int i = 0; i < other.size; i++) {
            addTerm(other.terms[i].coefficient, other.terms[i].exponent);
        }
        return *this;
    }

    Polynomial& operator-=(const Polynomial& other) {
        for (int i = 0; i < other.size; i++) {
            addTerm(-other.terms[i].coefficient, other.terms[i].exponent);
        }
        return *this;
    }

    Polynomial& operator*=(const Polynomial& other) {
        Polynomial result(capacity + other.capacity);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < other.size; j++) {
                int temp_coeff = terms[i].coefficient * other.terms[j].coefficient;
                int temp_exp = terms[i].exponent + other.terms[j].exponent;
                result.addTerm(temp_coeff, temp_exp);
            }
        }
        *this = result;
        return *this;
    }

    bool operator==(const Polynomial& other) const {
        if (size != other.size) return false;

        for (int i = 0; i < size; i++) {
            if (terms[i].coefficient != other.terms[i].coefficient ||
                terms[i].exponent != other.terms[i].exponent
                ) return false;
        }
        return true;
    }

    bool operator!=(const Polynomial& other) const {
        return !(*this == other);
    }

    bool operator<(const Polynomial& other) const {
        if (size == 0) return other.size > 0; // return false
        else if (other.size == 0) return false;

        return terms[size - 1].exponent < other.terms[other.size - 1].exponent;
    }

    bool operator>(const Polynomial& other) const {
        return (other < *this);
    }

};

ostream& operator<<(ostream& out, const Polynomial& other) {
    for (int i = 0; i < other.size; i++) {
        if (i > 0 && other.terms[i].coefficient > 0) {
            out << " + ";
        }
        out << other.terms[i].coefficient << "x^" << other.terms[i].exponent;
    }
    return out;
}

istream& operator>>(istream& in, Polynomial& other) {
    // Clean up existing terms array, if any
    if (other.terms != nullptr) {
        delete[] other.terms;
    }

    int store_size;
    cout << "Enter the number of terms you want for the polynomial: ";
    in >> store_size;

    other.size = store_size;
    other.terms = new Term[other.size];

    for (int i = 0; i < other.size; i++) {
        cout << "Enter Coefficient for term " << i + 1 << ": ";
        in >> other.terms[i].coefficient;
        cout << "Enter Exponent for term " << i + 1 << ": ";
        in >> other.terms[i].exponent;
    }

    return in;
}

int main() {
    try {
        Polynomial poly1, poly2;
        cout << "Enter the first polynomial:\n";
        cin >> poly1;
        cout << "Enter the second polynomial:\n";
        cin >> poly2;

        cout << "Polynomial 1: " << poly1 << endl;
        cout << "Polynomial 2: " << poly2 << endl;

        Polynomial sum = poly1 + poly2;
        Polynomial diff = poly1 - poly2;
        Polynomial prod = poly1 * poly2;

        cout << "Sum: " << sum << endl;
        cout << "Difference: " << diff << endl;
        cout << "Product: " << prod << endl;

        poly1 += poly2;
        cout << "After +=, Polynomial 1: " << poly1 << endl;

        poly1 -= poly2;
        cout << "After -=, Polynomial 1: " << poly1 << endl;

        poly1 *= poly2;
        cout << "After *=, Polynomial 1: " << poly1 << endl;

        if (poly1 == poly2) {
            cout << "Polynomial 1 is equal to Polynomial 2" << endl;
        } else {
            cout << "Polynomial 1 is not equal to Polynomial 2" << endl;
        }

        if (poly1 < poly2) {
            cout << "Polynomial 1 is less than Polynomial 2" << endl;
        } else if (poly1 > poly2) {
            cout << "Polynomial 1 is greater than Polynomial 2" << endl;
        }

    } catch (const Error& e) {
        e.showError();
    }

    return 0;
}
