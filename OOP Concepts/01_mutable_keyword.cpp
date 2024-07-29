#include <iostream>
using namespace std;

class Box {
private:
    mutable int width;
public:
    Box(int w) : width(w) {}
    void setWidth(int w) const {
        width = w;
    }
    int getWidth() const {
        return width;
    }
};

int main() {
    const Box b(10);
    b.setWidth(20);
    cout << "Width: " << b.getWidth() << endl; // Output: Width: 20
    return 0;
}
