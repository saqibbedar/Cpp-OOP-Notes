#include <iostream>

const int MAX_SIZE = 101;

class Set {
private:
    bool set[MAX_SIZE];

public:
    Set(int size);
    Set operator+(const Set& other) const;
    Set operator-(const Set& other) const;
    Set operator*(const Set& other) const;
    // Other required member functions and constructors
};

Set::Set(int size) {
    if (size <= 0 || size > MAX_SIZE) {
        throw std::invalid_argument("Invalid size for Set");
    }
    for (int i = 0; i < size; ++i) {
        set[i] = false;
    }
}

Set Set::operator+(const Set& other) const {
    Set result(*this);
    for (int i = 0; i < MAX_SIZE; ++i) {
        result.set[i] |= other.set[i];
    }
    return result;
}

Set Set::operator-(const Set& other) const {
    Set result(*this);
    for (int i = 0; i < MAX_SIZE; ++i) {
        result.set[i] &= !other.set[i];
    }
    return result;
}

Set Set::operator*(const Set& other) const {
    Set result(*this);
    for (int i = 0; i < MAX_SIZE; ++i) {
        result.set[i] &= other.set[i];
    }
    return result;
}

int main() {
    int size;
    std::cout << "Enter the size of the set (1-100): ";
    std::cin >> size;

    Set set(size);

    // Implement the rest of the code to get user input and use the Set class
}