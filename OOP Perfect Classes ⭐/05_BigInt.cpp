#include <iostream>
#include <string>
using namespace std;

class BigInt
{
    static const int Max_length = 40;
    int digits[Max_length];
    void initialize_array(); // useful function
    friend ostream &operator<<(ostream &, const BigInt &);

public:
    BigInt()
    {
        initialize_array(); // initialize array elements to zero
    }

    BigInt(const string& number)
    {
        initialize_array(); // initialize array with zeros first

        int length = number.length();
        int starting_index = Max_length - length; // setting index, to leave zeros at left side

        for (int i = starting_index, j = 0; i < Max_length; i++, j++)
        {
            digits[i] = number[j] - '0'; // converting character to integer
        }
    }

    void Input(const string& number)
    {
        initialize_array(); // initialize with 0

        int length = number.length();
        int starting_index = Max_length - length;

        for (int i = starting_index, j = 0; i < Max_length; i++, j++)
        {
            digits[i] = number[j] - '0';
        }
    }

    // operator overloading
    BigInt operator+(const BigInt& number);
    BigInt operator-(const BigInt& number);
    BigInt operator*(const BigInt& number);
    BigInt operator/(const BigInt& number);

    BigInt operator%(const BigInt& number);

    bool operator<(const BigInt& number) const;
    bool operator>(const BigInt& number) const;
    bool operator==(const BigInt& number) const;
    bool operator!=(const BigInt& number) const;
    bool operator>=(const BigInt& number) const;
    bool operator<=(const BigInt& number) const;
};

// useful function
void BigInt::initialize_array()
{
    for (int i = 0; i < Max_length; i++)
    {
        digits[i] = 0;
    }
}

// print
ostream &operator<<(ostream &out, const BigInt& number)
{
    int i = 0;
    while (i < BigInt::Max_length && number.digits[i] == 0)
    { // iterating to skip the leading zeros and set index where it founds a number then break the loop
        i++;
    }
    if (i == BigInt::Max_length) // if i is same as Max_length then all numbers are 0 so print 0
        out << "0";
    else
    {
        for (; i < BigInt::Max_length; i++)
        { // print the numbers from the i index
            out << number.digits[i];
        }
    }
    return out;
}

// operator overloading

BigInt BigInt::operator+(const BigInt& number)
{
    BigInt result;
    int carry = 0;

    // iterate from right side to left side
    for (int i = Max_length - 1; i >= 0; i--)
    {
        int sum = digits[i] + number.digits[i] + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }

    return result;
}

BigInt BigInt::operator-(const BigInt& number)
{
    BigInt result;
    int borrow = 0; // Variable to store borrow value

    // Iterate from rightmost to leftmost
    for (int i = Max_length - 1; i >= 0; i--) 
    {

        int difference = digits[i] - number.digits[i] - borrow;

        // If difference is negative, we need to borrow from the next higher digit
        if (difference < 0)
        {
            difference += 10; // Add 10 to difference (borrow 1 from the next digit)
            borrow = 1;       // Set borrow to 1 for the next iteration
        }
        else
        {
            borrow = 0; // Reset borrow if no borrowing is needed
        }

        result.digits[i] = difference;
    }

    return result;
}

BigInt BigInt::operator*(const BigInt& number)
{
    BigInt result;

    for (int i = Max_length - 1; i >= 0; i--)
    {
        BigInt temp;
        int carry = 0;

        for (int j = Max_length - 1; j >= 0; j--)
        {
            int product = digits[i] * number.digits[j] + carry;
            temp.digits[j] = product % 10;
            carry = product / 10;
        }

        // Shift temp digits to the left based on i
        for (int k = 0; k < Max_length - 1 - i; k++)
        {
            temp.digits[k] = 0;
        }

        result = result + temp;
    }

    return result;
}

BigInt BigInt::operator/(const BigInt& number)
{
    BigInt temp = *this;
    BigInt result;

    while (temp >= number)
    {
        temp = temp - number;
        result = result + BigInt("1");
    }

    return result;
}

BigInt BigInt::operator%(const BigInt& number)
{
    BigInt temp = *this;
    while (temp >= number)
    {
        temp = temp - number;
    }
    return temp;
}

bool BigInt::operator<(const BigInt& number) const
{
    for (int i = 0; i < Max_length; i++)
    {
        if (digits[i] < number.digits[i])
            return true;
        if (digits[i] > number.digits[i])
            return false;
    }
    return false; // If all digits are equal
}

bool BigInt::operator>(const BigInt& number) const
{
    return !(*this < number) && !(*this == number);
}

bool BigInt::operator==(const BigInt& number) const
{
    for (int i = 0; i < Max_length; i++)
    {
        if (digits[i] != number.digits[i])
            return false;
    }
    return true; // If all digits are equal
}

bool BigInt::operator!=(const BigInt& number) const
{
    return !(*this == number);
}

bool BigInt::operator>=(const BigInt& number) const
{
    return (*this > number) || (*this == number);
}

bool BigInt::operator<=(const BigInt& number) const
{
    return (*this < number) || (*this == number);
}

int main()
{
    BigInt num1("12345678901234567890430582347");
    BigInt num2("98765432109876543210430582347");

    BigInt sum = num1 + num2;
    BigInt difference = num2 - num1;
    BigInt product = num1 * num2;
    BigInt quotient = num2 / num1;
    BigInt remainder = num2 % num1;

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder << endl;

    cout << "Comparison: " << endl;
    cout << "num1 > num2: " << (num1 > num2) << endl;
    cout << "num1 < num2: " << (num1 < num2) << endl;
    cout << "num1 == num2: " << (num1 == num2) << endl;
    cout << "num1 != num2: " << (num1 != num2) << endl;
    cout << "num1 >= num2: " << (num1 >= num2) << endl;
    cout << "num1 <= num2: " << (num1 <= num2) << endl;

    return 0;
}