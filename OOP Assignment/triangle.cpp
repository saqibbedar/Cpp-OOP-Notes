#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;

class myString
{
private:
    char *str;  // Pointer to hold the dynamically allocated string
    int length; // Length of the string

public:
    // Default constructor
    myString() : str(nullptr), length(0) {}

    // Convert constructor with int parameter
    myString(int n)
    {
        if (n < 0)
        {
            cout << "Error: Cannot create a string with negative length.\n";
            str = nullptr;
            length = 0;
            return;
        }
        length = n;
        str = new char[length + 1];
        str[length] = '\0'; // Null terminate the string
    }

    // Convert constructor with const char* parameter
    myString(const char *s)
    {
        if (!s)
        {
            cout << "Error: Null pointer passed to constructor.\n";
            str = nullptr;
            length = 0;
            return;
        }
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Copy constructor
    myString(const myString &other)
    {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Destructor
    ~myString()
    {
        delete[] str;
    }

    // Assignment operator
    myString &operator=(const myString &other)
    {
        if (this == &other) // Self-assignment check
            return *this;
        delete[] str; // Deallocate old memory
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        return *this;
    }

    // Addition operator
    myString operator+(const myString &other) const
    {
        myString temp;
        temp.length = length + other.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, other.str);
        return temp;
    }

    // Compound assignment operator (+=)
    myString &operator+=(const myString &other)
    {
        char *temp = new char[length + other.length + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        delete[] str;
        str = temp;
        length += other.length;
        return *this;
    }

    // Subscript operator ([])
    char &operator[](int index)
    {
        if (index < 0 || index >= length)
        {
            std::cerr << "Error: Index out of range.\n";
            // Returning a reference to a temporary. Not a good practice, but
            // it's done here for the sake of simplicity.
            return str[0];
        }
        return str[index];
    }

    // Function call operator (())
    myString operator()(int startingPoint, int endingPoint)
    {
        if (startingPoint < 0 || startingPoint >= length || endingPoint < startingPoint || endingPoint > length)
        {
            cout << "Invalid starting or ending point" << endl;
            // Returning empty object as an error indicator
            return myString();
        }

        myString temp(endingPoint - startingPoint); // Creating object by passing length
        for (int i = 0; i < temp.length; i++)
        {
            temp.str[i] = str[startingPoint + i];
        }
        temp.str[temp.length] = '\0';
        return temp;
    }

    // Insertion operator (<<)
    friend std::ostream &operator<<(std::ostream &os, const myString &str)
    {
        os << str.str;
        return os;
    }

    // Extraction operator (>>)
    friend std::istream &operator>>(std::istream &is, myString &str)
    {
        char temp[10000]; // Temporary hold the input values
        is >> temp;
        str = myString(temp); // Use the convert constructor to create a myString object
        return is;
    }

    // Relational operators (<, <=, >, >=, ==, !=)
    bool operator<(const myString &other) const
    {
        return strcmp(str, other.str) < 0;
    }
    bool operator<=(const myString &other) const
    {
        return strcmp(str, other.str) <= 0;
    }
    bool operator>(const myString &other) const
    {
        return strcmp(str, other.str) > 0;
    }
    bool operator>=(const myString &other) const
    {
        return strcmp(str, other.str) >= 0;
    }
    bool operator==(const myString &other) const
    {
        return strcmp(str, other.str) == 0;
    }
    bool operator!=(const myString &other) const
    {
        return strcmp(str, other.str) != 0;
    }
};

int main()
{
    myString str1("Hello");
    myString str2("World");
    cout << str1(1, 3) << endl;

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    myString str3 = str1 + str2;
    std::cout << "str1 + str2: " << str3 << std::endl;

    str1 += str2;
    std::cout << "str1 += str2: " << str1 << std::endl;

    std::cout << "Enter a string: ";
    std::cin >> str1;
    std::cout << "You entered: " << str1 << std::endl;

    if (str1 < str2)
    {
        std::cout << str1 << " is less than " << str2 << std::endl;
    }
    else
    {
        std::cout << str1 << " is not less than " << str2 << std::endl;
    }

    return 0;
}
