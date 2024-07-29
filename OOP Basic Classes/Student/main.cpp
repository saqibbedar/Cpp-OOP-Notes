#include "Student.h"

int main(){
    int *arr = new int(0);

    Student s1("John", 20, arr);
    s1.input();
    s1.display();

    delete[] arr;
    return 0;
}
