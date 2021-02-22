#include <iostream>
#include <cstdlib>
#include "testQueue.h"
#include "queue.h"
using namespace std;

testQueue::testQueue()
{

}

testQueue::~testQueue()
{
    delete arr; // you are not required to test this function;
    // however, are there issues with it? // Yes: discussed in attributes list
}

//Test by Dylan
/*
Test ID: Queue of 3 -QO3
 Unit: queue::size()
 Description: test to see if queue::size() returns 3 when there are 3 nodes of integers
 Test steps:
 1. construct queue and enqueue 3 nodes
 2. run queue::size()
 3. determine if the value returned is correct.
 Test data: size = 3
 Precondition: 3 nodes are inserted to queue
 Post condition: there are still 3 nodes in queue.
 Expected result: 3 nodes in queue; 3 is returned
 Actual result: 4 was returned.
 Status: failure
 */
void testQueue::testSize()
{
    cout << "START QO3 test\n";
    queue tests(SIZE);
    tests.enqueue(1);
    tests.enqueue(2);
    tests.enqueue(7);
    cout << "QO3 test results: " <<  tests.size() << endl << "END QO3 test\n\n";

}

//Test by Nate
/* Test ID: Empty Queue Check - EQC
    Unit: testIsEmpty()
    Description: This test runs a check to see if testIfEmpty() returns 1 when
    queue is actually empty
    Test Steps:
        1. Construct empty queue
        2. call testIsEmpty()
        3. Evaluate the return value
    Test data: SIZE = 0
    Precondition: queue is empty
    Postcondition: queue is empty
    Expectation: test returns 1 and the queue is empty
    Actual: test returned 0 and the the queue is empty
    Status: failed
*/
void testQueue::testIsEmpty()
{
    cout << "START EQC test\n";
    queue test(SIZE);
    cout << "EQC test result: " << test.isEmpty() << endl << "END EQC test\n\n";
}

//Test by Dylan
/*
Test ID: Queue Full Check - QFC
 Unit: queue::isFull()
 Description: test to see if queue::isFull() returns 1 when the queue is full.
 Test steps:
 1. construct queue with a size of 10 and enqueue 10 nodes
 2. run queue::isFull()
 3. determine if the value returned is correct.
 Test data: size = 10
 Precondition: 10 nodes are inserted to queue
 Post condition: there are still 10 nodes in queue.
 Expected result: 10 nodes in queue; 1 is returned
 Actual result: 10 nodes are enqueued. 1 is returned.
 Status: Pass
 */
void  testQueue::testIsFull()
{
    cout << "START QFC test\n";
    queue tests(SIZE);
    tests.enqueue(1);
    tests.enqueue(2);
    tests.enqueue(7);
    tests.enqueue(7);
    tests.enqueue(7);
    tests.enqueue(7);
    tests.enqueue(7);
    tests.enqueue(7);
    tests.enqueue(7);
    tests.enqueue(7);
    cout << "QFC test results: " << tests.isFull() << endl << "END QFC test\n\n";
}

//Test by Dylan
/*
Test ID: dequeue one element - DOE
 Unit: queue::dequeue()
 Description: test to see if queue::dequeue revoves the first inserted node
 Test steps:
 1. construct queue and enqueue 3 nodes
 2. run queue::dequeue()
 3. determine if the first element was the one that was dequeued.
 Test data: size = 3
 Precondition: 3 nodes are inserted to queue. the first element is '1'
 Post condition: there are 2 nodes in queue.
 Expected result: 2 nodes in queue; "removing 1" is returned
 Actual result: "removing 1" is returned
 Status: Pass
 */

void testQueue::testDequeue()
{
    cout << "START DOE test\n";
    queue tests(SIZE);
    tests.enqueue(1);
    tests.enqueue(2);
    tests.enqueue(7);
    cout << "DOE test result: ";
    tests.dequeue();
    cout << "END DOE test\n\n";
}

//Test by Dylan
/*
Test ID: Dequeue Empty - DE
        Unit: queue::dequeue()
Description: test to see if queue::dequeue() correctly determines if the queue is empty and terminates.
        Test steps:
1. construct queue and enqueue nothing
2. run queue::dequeue()
3. determine if what is returned is correct.
Test data: size = 0
Precondition: 0 nodes are inserted to queue
Post condition: there are still 0 nodes in queue.
Expected result: 0 nodes in queue; "program terminated" is returned.
Actual result: "dequeued 0"
Status: failed
*/

void testQueue::testDequeueEmpty()
{
    cout << "START DE test\n";
    queue test(SIZE);
    cout << "DE test result: ";
    test.dequeue();
    cout << "END DE test\n\n";
}

//Test by Nate
/* Test ID: Empty Queue Enqueue Check - EQEC
    Unit: testEnqueue()
    Description: This test runs a check to see if testEnqueue()
    is able to add items to an empty queue
    Test Steps:
        1. call testEnqueue()
        2. 10 items are inserted
        3. Evaluate results
    Test data: SIZE = 10; Insert 10 items - Values 1-10;
    Precondition: the queue is empty
    Postcondition: the queue is full
    Expectation: queue enqueues 10 items 1-10; no Overflow
    Actual: queue enqueues 10 items 1-10; no Overflow
    Status: passed
*/
void testQueue::testEnqueue()
{

    cout << "START EQEC test\nEQEC test results: \n";
    queue test(SIZE);
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    test.enqueue(4);
    test.enqueue(5);
    test.enqueue(6);
    test.enqueue(7);
    test.enqueue(8);
    test.enqueue(9);
    test.enqueue(10);
    cout << "END EQEC test\n\n";

}

//Test by Nate
/* Test ID: Full Queue Enqueue Check - FQEC
    Unit: testEnqueue()
    Description: This test runs a check to see if testEnqueueFull()
    is able to return the Overflow error message if we try and enqueue more than the size is allotted for
    Test Steps:
        1. call testEnqueueFull()
        2. Insert one item more than the allotted size
        3. Evaluate results
    Test data: SIZE = 1; Insert 2 items - Value: 1-10;
    Precondition: the queue has one item; no Overflow error
    Postcondition: the queue has two items; Overflow error
    Expectation: queue tries to enqueue 2 items; Overflow message displays
    Actual: queue tries to enqueue 2 items; Overflow message displays
    Status: passed
*/
void testQueue::testEnqueueFull()
{
    cout << "START FQEC test\nFQEC test results: \n";
    queue test(1);
    test.enqueue(1);
    test.enqueue(2);
    cout << "END FQEC test\n\n";
}

//Test by Nate
/* Test ID: Queue Peek Check - QPC
    Unit: testPeek()
    Description: This test runs a check to see if testPeek()
    returns the correct item which should be rear[arr]
    Test Steps:
        1. Construct a full queue
        2. call testPeek()
        3. Evaluate the return value
    Test data: SIZE = 10; Insert 10 items - Values 1-10;
    Precondition: the rear value is 10
    Postcondition: the rear value returned is 10
    Expectation: test returns 10
    Actual: test returned 10
    Status: passed
*/
void testQueue::testPeek()
{
    cout << "START QCP test\n";
    queue test(SIZE);
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    test.enqueue(4);
    test.enqueue(5);
    test.enqueue(6);
    test.enqueue(7);
    test.enqueue(8);
    test.enqueue(9);
    test.enqueue(10);
    cout << "QPC test result: " << test.peek() << endl << "END QPC test\n\n";
}

//Test by Nate
/* Test ID: Empty Queue Peek Check - EQPC
    Unit: testPeek()
    Description: This test runs a check to see if testPeek()
    outputs the Underflow error message when the queue is empty
    Test Steps:
        1. Construct an empty queue
        2. call testPeekEmpty()
        3. Evaluate the output
    Test data: SIZE = 10; Insert 0 items
    Precondition: the queue is empty
    Postcondition: the queue is empty
    Expectation: Underflow message dsplays
    Actual: test returned 0
    Status: failed
*/
void testQueue::testPeekEmpty()
{
    cout << "START EQPC test\n";
    queue test(SIZE);
    cout << "EQCP test results: " << test.peek() << endl << "END EQCP test\n\n";
}
