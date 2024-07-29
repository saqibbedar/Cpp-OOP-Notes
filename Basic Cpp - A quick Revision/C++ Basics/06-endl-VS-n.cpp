// We have used mostly '\n' and endl for breaking the line but there is difference between them as '\n' just inserts a new line, whereas endl inerts new line and flushes the stream(output buffer). 

// Therefore, cout<<endl; is equivalent to cout<<"\n"<<flush;

// In some cases, it is better to use '\n', because it saves time by not flushing the entire line and thus improves the time complexity of the program.

#include <iostream>
using namespace std;

int main()
{
    cout<<"\n"; // occupy memory space of 1 byte
    cout<<endl; // does not occupy memory space
    cout<<"\n"<<flush;
    return 0;
}

// other differences: 
// endl: it is manipulator, it does not occupy memory, it is a identifier and would not specify any meaning when stored in string, it keeps flushing the buffer throughout the proccess.

// '\n': it is a character and it occupy space of 1 byte, and it can be stored in string and do its job for breaking the line, it flushes the output only once at the end of the program.

// Flushing the buffer, in the context of C++ programming, refers to the process of ensuring that any data that has been written into an output buffer is actually sent to the intended device (like the console screen, a file, etc.).

// When you write data using cout, the data doesn't usually go directly to the console screen. Instead, it first goes into an output buffer. The buffer is a block of memory that holds the data temporarily. The reason for this is efficiency. Writing to a buffer in memory is much faster than writing to the console screen or a file. So, the data is collected in the buffer, and then written out to the actual device all at once. This process is known as "flushing the buffer".

// Now, when you use endl, it inserts a newline character, and then it flushes the buffer. This means it forces the data to be written out immediately, even if the buffer isn't full yet. This can be useful in some situations, because it ensures that you see the output right away. But it can also slow down your program, because flushing the buffer is a relatively slow operation.

// On the other hand, when you use '\n', it simply inserts a newline character into the buffer. It doesn't flush the buffer. The buffer will be flushed automatically when it's full, or when the program ends, or when you manually flush it using cout.flush() or cout << flush.