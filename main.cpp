// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn
/*
 * Dylan Myer and Nate Anderson
 * 2/20/2021
 * MA1

ATTRIBUTES LIST:

 1. The usage of return statements in if statements.
 2. It is not explicitly clear to the user of the code that
 the queue only stores/contains integer values in each item.
 3. There is potential of a memory leak when te destructor is called
 when delete arr; executes.
 4. Use another solution other than modulus for enqueue, or make
 it more clear to the user what is happening, as it is unclear
 what exactly is going on at a glance.
 5. Executing calculations within the return statement rather than
 setting up a boolean and returning it after all calculations.

 */

#include <iostream>
#include <cstdlib>
#include "testQueue.h"
using namespace std;

// main function
int main()
{
    // call your test functions here!
    testQueue test;

    test.testSize();
    test.testIsEmpty();
    test.testIsFull();
    test.testDequeue();
    test.testDequeueEmpty();
    test.testEnqueue();
    test.testEnqueueFull();
    test.testPeek();
    test.testPeekEmpty();

    return 0;
}


