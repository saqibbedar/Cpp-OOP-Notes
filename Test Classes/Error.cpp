#include <iostream>

class Error
{
public:
    void index_error();
    void size_error();
};

void Error::index_error()
{
    std::cout << "Error: index is undefined.";
}
void Error::size_error()
{
    std::cout << "Error: size error.";
};