#pragma once
#include <iostream>
#include "Node.h"

template <class P, class K>
class Stack
{
private:
    Node<P, K> *top; // ptr to the top
    int numNodes; // Number of nodes in stack

public:
    Stack() 
    {
        numNodes = 0;
        top = nullptr;
    }

    Stack(const Stack& initStack)
    {
        numNodes = 0;
        push(initStack.top);
    }

    void push(P newCommand, K newDef)
    {
            top = new Node<P, K>(newCommand, newDef, top);
            numNodes++;
    }

    P pop()
    {

    }

    //My attempt at search, clearing the list, copying, and overloading operators
    //but I couldn't get it to work with my keyed nodes

    //void copy(Node<P, K>* endPtr) //function used to traverse and copy the stack
    //{
    //    if (endPtr != nullptr)
    //    {
    //        copy(top->getNext());
    //        this->push(top->getPayload());
    //    }
    //}

    //void clear()
    //{
    //    Node<P, K>* crawler = top;
    //    Node<P,K>* crawler2;
    //    while (crawler)
    //    {
    //        crawler2 = crawler;
    //        crawler = crawler->getNext(); //couldn't convert from void to Node<P, K> ?
    //        delete(crawler2);
    //    }
    //    top = nullptr;
    //}

    //Stack& operator =(const Stack& FromStack)
    //{
    //    if (this != &FromStack)
    //    {
    //        this->clear();
    //        this->copy(FromStack.top);
    //    }
    //    return *this;
    //}

  /*  bool operator==(const Stack& lhs) const
    {
        bool retVal = true;
        if (lhs.numNodes != this->numBoxes)
        {
            retVal = false;
        }
        else
        {
            Node<P, K>* tempPtrLhs = lhs.top;
            Node<P, K>* tempPtrRhs = this->top;
            while (tempPtrLhs != nullptr && retVal)
            {
                if (tempPtrLhs->getPayload() != tempPtrRhs->getPayload())
                {
                    retVal = false;
                }
                tempPtrLhs = tempPtrLhs->getNext();
                tempPtrRhs = tempPtrRhs->getNext();
            }
        }
        return retVal;
    }*/

 /*   bool search(string searchTerm) // couldn't figure how to convert void to Node<P,K>
    {
      
        bool retVal = false;
        Node<P, K>* tempPtrRhs = this->top;
        while (tempPtrRhs != nullptr && !retVal)
        {

            if (searchTerm == tempPtrRhs->getPayload())
            {
                retVal = true;
            }
            tempPtrRhs = tempPtrRhs->getNext();
            
        }
        return retVal;
    }*/

};

