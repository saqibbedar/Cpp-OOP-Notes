// OOP Quiz 1 - Monday, 3 march 2024
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string setWidth(int width){
    string store = "";
    while (width > 0)
    {
        store += "*";
        width--;
    }
    return store;
}

int main()
{
    // Question 1:
    // int ar[6] = {11, 22, 33, 44, 55, 66};
    // int *ptr = ar;
    // ptr++;
    // cout<<endl<<setWidth(10)<<" Question 1 "<<setWidth(10)<<endl<<endl;
    // cout<<*ptr<<endl; // 22
    // cout<<*ptr++<<endl; // 22
    // cout<<*++ptr<<endl; // 44
    // cout<<(*ptr)++<<endl; // 44
    // cout<<++*ptr<<endl; // 46
    // cout<<*(ptr-3)<<endl; // 11
    // cout<<*ptr-2<<endl; // 44
    // cout<<ar[3]<<endl; // 46
    // cout<<ptr[1]<<endl; // 55
    // cout<<*ptr<<endl; // 46

    // Question 2:
    cout<<endl<<setWidth(10)<<" Question 2 "<<setWidth(10)<<endl<<endl;
    char text[] ="This is an easy exam...";// size is 23+'\0' = 24
    char *ptr1, *ptr2;
    int len = strlen(text);

    ptr1 = text;
    ptr2 = text + len-1;
    
    cout<<ptr1<<endl;
    cout<<ptr2<<endl;
    cout<<(char)++*ptr1<<endl;
    cout<<ptr1<<endl;
    cout<<ptr1+8<<endl;
    cout<<*text-1<<endl;
    ptr1 += 5;
    ptr2 -= 6;
    cout<<ptr1<<endl;
    cout<<ptr2<<endl;
    cout<<ptr1[2]<<endl;
    cout<<*(ptr2+1)<<endl;

    cout<<endl<<setWidth(10)<<" Question 3 "<<setWidth(10)<<endl<<endl;

    int x = 0;
    do{
        cout<<"Enter no. b/w 1 to 10: ";
        cin>>x;
    }while(x<0 || x>10);

    // allocation
    double **matrix = new double*[x];
    for(int i= 0; i<x; i++){
        matrix[i] = new double[i];
    }

    // read matrix
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            cout<<"Enter element at index ["<<i<<"]"<<"["<<j<<"] ";
            cin>>matrix[i][j];
        }
    }

    // main questions logic
    double sum1 = 0, sum2 = 0;
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            if(i == j)
                sum1 += matrix[i][j];
            if(i+j == x-1)
                sum2 += matrix[i][j];
        }
    }

    if(sum1 == sum2){
        cout<<"Equal";
    }else{
        cout<<"Not equal";
    }

    // deallocation
    for(int i=0; i<x; i++){
        delete[] matrix[i];
    }
    delete matrix;
    return 0;
}

/*

Description for second question:

1. `char text[] ="This is an easy exam...";` This line declares a character array `text` and initializes it with the string "This is an easy exam...".

2. `char *ptr1, *ptr2;` This line declares two character pointers `ptr1` and `ptr2`.

3. `int len = strlen(text);` This line declares an integer `len` and initializes it with the length of the string stored in `text`.

4. `ptr1 = text;` This line assigns the address of the first character of `text` to `ptr1`.

5. `ptr2 = text + len-1;` This line assigns the address of the last character of `text` to `ptr2`.

6. `cout<<ptr1<<endl;` This line prints the string starting from the character pointed to by `ptr1`, which is the entire string "This is an easy exam...".

7. `cout<<ptr2<<endl;` This line prints the string starting from the character pointed to by `ptr2`, which is the string "...".

8. `cout<<(char)++*ptr1<<endl;` This line increments the ASCII value of the character pointed to by `ptr1` by 1 and then prints it. Since `ptr1` points to 'T', which has an ASCII value of 84, incrementing it by 1 gives us 'U'.

9. `cout<<ptr1<<endl;` This line prints the string starting from the character pointed to by `ptr1`, which is now "Uhis is an easy exam...".

10. `cout<<ptr1+8<<endl;` This line prints the string starting from the character 8 positions from the character pointed to by `ptr1`, which is "an easy exam...".

11. `cout<<*text-1<<endl;` This line decrements the ASCII value of the first character in `text` by 1 and then prints it. Since the first character is now 'U', decrementing it by 1 gives us 'T'.

12. `ptr1 += 5;` This line moves the `ptr1` pointer 5 positions to the right.

13. `ptr2 -= 6;` This line moves the `ptr2` pointer 6 positions to the left.

14. `cout<<ptr1<<endl;` This line prints the string starting from the character pointed to by `ptr1`, which is "is an easy exam...".

15. `cout<<ptr2<<endl;` This line prints the string starting from the character pointed to by `ptr2`, which is "easy exam...".

16. `cout<<ptr1[2]<<endl;` This line prints the character at the 2nd index from the character pointed to by `ptr1`, which is ' ' (space).

17. `cout<<*(ptr2+1)<<endl;` This line prints the character at the 1st index from the character pointed to by `ptr2`, which is 'a'.


Another description for Question2 

1. `char text[] ="This is an easy exam...";` This line declares a character array `text` and initializes it with the string "This is an easy exam...". In C++, a string is essentially an array of characters ending with a null character (`\0`). So, `text` is an array of characters.

2. `char *ptr1, *ptr2;` These are pointers that can point to characters. They don't contain any data yet.

3. `ptr1 = text;` Here, `ptr1` is assigned the address of the first character of `text`. But when you print a character pointer in C++, it prints all characters starting from the pointed character up to the null character (`\0`). That's why it prints the whole string "This is an easy exam...".

4. If you had initialized the array in a different way, like `char text[] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', 'n', ' ', 'e', 'a', 's', 'y', ' ', 'e', 'x', 'a', 'm', '.', '.', '.', '\0'};`, the result would be the same. The null character at the end is important because it marks the end of the string. Without it, the program wouldn't know where the string ends.

5. `cout<<(char)++*ptr1<<endl;` Here, the character that `ptr1` points to ('T') is incremented by 1. The ASCII value of 'T' is 84, so incrementing it by 1 gives us 'U' (ASCII value 85). The `(char)` cast is used to print the character 'U' instead of its ASCII value.

6. `cout<<ptr1+8<<endl;` Here, `ptr1+8` points to the character 8 positions from the character pointed to by `ptr1`. When you add an integer to a pointer in C++, it moves the pointer that many positions to the right. So, `ptr1+8` points to the character 'a' in "an easy exam...", and the `cout` statement prints all characters from there up to the null character.

7. `cout<<*text-1<<endl;` Here, `*text` is the first character in `text`, which is now 'U'. When you subtract 1 from it, you get 'T' (ASCII value 84). The `cout` statement prints this character.

8. `ptr1 += 5;` and `ptr2 -= 6;` These lines move the `ptr1` pointer 5 positions to the right and the `ptr2` pointer 6 positions to the left, respectively.

9. `cout<<ptr1[2]<<endl;` Here, `ptr1[2]` is the character at the 2nd index from the character pointed to by `ptr1`. In C++, you can use array-like indexing with pointers.

10. `cout<<*(ptr2+1)<<endl;` Here, `*(ptr2+1)` is the character at the 1st index from the character pointed to by `ptr2`. The `*` operator is used to dereference the pointer, i.e., to get the character it points to.

*/