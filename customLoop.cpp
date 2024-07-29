#include <iostream>
using namespace std;

int customLoop(int start, int end) {
    if (start > end) {
        return;
    }
    cout << start << endl;
    customLoop(start + 1, end);
}

int main()
{
    customLoop(1,5);
    return 0;
}

/*

What optimizations can be applied to the generated machine code or bytecode for loops during the compilation process?

How do compilers handle nested loops and their interactions with other control flow structures in a programming language?

What considerations should be taken into account when designing a new control flow structure for a custom programming language?

How do different programming paradigms (e.g., procedural, object-oriented) influence the implementation of loops and control flow structures in a programming language?

What impact does the choice of data structures have on the efficiency and performance of loops in a programming language?

*/
