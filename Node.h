#pragma once
#include <ostream>
#include "Command.h"
#include "profile.h"
using namespace std;

template <class P, class K>
class Node
{
private:
    //data stored in each node
    P payload;
    K key;
    //ptr to next node or null
    Node* nextPtr = nullptr;

public:
    //Constructor
    Node(P newPayload, K newKey, Node* newNextPtr)
    {
        setPayload(newPayload);
        setKey(newKey);
        setNext(newNextPtr);
    }

    //Accessors
    int getNext()
    {
        return nextPtr;
    }

    void getPayload()
    {
        return payload;
    }

    //Mutators
    void setPayload(P newPayload)
    {
        payload = newPayload;
    }

    void setKey(K newKey)
    {
        key = newKey;
    }

    void setNext(Node* newNextPtr)
    {
        nextPtr = newNextPtr;
    }


    //Deconstructors
    ~Node()
    {

    }


};

