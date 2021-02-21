#define SIZE 10

// Class for testQueue
class testQueue
{
    int* arr;		// array to store testQueue elements
    int capacity;	// maximum capacity of the testQueue
    int front;		// front points to front element in the testQueue (if any)
    int rear;		// rear points to last element in the testQueue
    int count;		// current size of the testQueue

public:
    testQueue(); 	// constructor
    ~testQueue();   // destructor

    void testSize();
    void testIsEmpty();
    void testIsFull();
    void testDequeue();
    void testDequeueEmpty();
    void testEnqueue();
    void testEnqueueFull();
    void testPeek();
    void testPeekEmpty();
};
