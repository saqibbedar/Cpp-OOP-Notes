/* 

what is difference between them:

int getDaty();
const int getDay();
int getDay() const;
const int getDay() const;

1. int getDay();

This is a member function declaration indicating that `getDay` returns an integer. Without any qualifiers like `const`, it implies that the function can modify the object's state on which it is called.

2. const int getDay();

This declaration implies that `getDay` returns a constant integer. However, without `const` at the end, it doesn't imply anything about the function's effect on the object's state. It can still modify the object's state.

3. int getDay() const;

This is a member function declaration indicating that `getDay` returns an integer and it's a const member function. It means that this function promises not to modify the state of the object on which it is called. This is particularly useful when you have a const reference or pointer to an object and you still want to call a member function that doesn't modify the object's state.

4. const int getDay() const;

This is equivalent to the previous one but less common. It indicates that `getDay` returns a constant integer and it's a const member function. The return type being `const` here is redundant, as primitive types like `int` are always returned by value and cannot be modified through the return value. So, this declaration is equivalent to `int getDay() const;

*/

// Here's an example to illustrate the differences:


class Example {
    int day;

public:
    int getDay(); // Can modify 'day'
    const int getDay(); // Can modify 'day', but the return value is constant
    int getDay() const; // Cannot modify 'day', but can modify the return value
    const int getDay() const; // Same as the previous one
};


// You would implement these member functions as follows:


int Example::getDay() {
    day = 10; // Can modify 'day'
    return day;
}

const int Example::getDay() {
    day = 10; // Can modify 'day', but return value is constant
    return day;
}

int Example::getDay() const {
    // day = 10; // This would cause a compilation error, as 'day' cannot be modified in a const member function
    return day;
}

const int Example::getDay() const {
    // day = 10; // This would cause a compilation error, as 'day' cannot be modified in a const member function
    return day; // The return value is constant, but it's redundant for primitive types like 'int'
}


// I hope this clarifies the differences between these function declarations!