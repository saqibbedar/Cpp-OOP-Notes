// Assuming class Thing is defined, how many times is the copy constructor called in the following code?

class Thing{};

Thing f(Thing w) {
    Thing v(w);  // (1) Copy constructor
    Thing u = v; // (2) Copy constructor
    return u;    // (3) Copy constructor (typically call copy constructor when returning)
}

int main() {
    Thing x;
    x = f(x); // (4) Copy constructor
}

// Four times it would be called