#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const char* fortunes[5]={
        "Its a good day for you!",
        "You will get money!",
        "You will get good marks!",
        "You will get job soon!",
        "It's happy day for you!"
    };

    // initialize random seed
    srand(time(0));

    // Generate a random index between 0 and 4
    int index = rand() % 5;
    
    cout<<index<<fortunes[index]<<endl;

    return 0;
}