#pragma once
#include "AVLNode.h"
#include <iostream>

using namespace std;

template <class T>
class AVLTree
{
private:
    AVLNode<T>* root; //root of tree

    //helper to add new values - similar to our bst addhelper
    //also, credit to guru 99, used as a reference to learn how to balance with insertion
    AVLNode<T>* insertHelper(AVLNode<T>* root, T val) 
    {
        if (root->getPayload() > val) {
            if (!root->getLeft()) {
                root->setLeft(new AVLNode<T>(val, nodeHeight(root)));
            }
            else {
                insertHelper(root->getLeft(), val);
            }
        }
        else {
            if (!root->getRight()) {
                root->setRight(new AVLNode<T>(val, nodeHeight(root)));
            }
            else {
                insertHelper(root->getRight(), val);
            }
        }
        
        if (getBalanceFactor(root) == 2 && getBalanceFactor(root->getLeft()) == 1) {
            root = leftRotation(root);
        }
        else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->getRight()) == -1) {
            root = rightRotation(root);
        }
        else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->getRight()) == 1) {
            root = rlRotation(root);
        }
        else if (getBalanceFactor(root) == 2 && getBalanceFactor(root->getLeft()) == -1) {
            root = lrRotation(root);
        }

        return 0;
    }

public:
    //Construct!
    AVLTree() : root(nullptr) {}

    //Functions:

    void insert(const T newData) 
    {
        if (this->root)
        {
            this->insertHelper(root, newData);
        }
        else
            this->root = new AVLNode<T>(newData, 1);
    }

    void validate() 
    {
        cout << endl << validateHelper(root)<< endl;
    }
    //credit: GeeksforGeeks, they helped understand how to create a conditional check
    //to check the difference between the heights of the left and right
    //then the difference, if -1,0,or 1 it is validated, hence the absolute value func
    bool validateHelper(AVLNode<T>* root)
    {
        int leftHeight; /* for height of left subtree */
        int rightHeight; /* for height of right subtree */

        if (root == nullptr)
            return 1;

        leftHeight = heightHelper(root->getLeft());
        rightHeight = heightHelper(root->getRight());

        if (abs(leftHeight - rightHeight) <= 1 && validateHelper(root->getLeft()) && validateHelper(root->getRight()))
            return 1;

        //if it returns here this means it is not a balanced tree
        return 0;
    }

    //used Guru 99 as a reference and a way to unsderstand how to find the height of an
    //individual node

    int nodeHeight(AVLNode<T>* root)
    {

        if (root->getLeft() && root->getRight()) 
        {
            if (root->getLeft()->getHeight() < root->getRight()->getHeight())
                return root->getRight()->getHeight() + 1;
            else return  root->getLeft()->getHeight() + 1;
        }
        else if (root->getLeft() && root->getRight() == nullptr) 
        {
            return root->getLeft()->getHeight() + 1;
        }
        else if (root->getLeft() == nullptr && root->getRight()) 
        {
            return root->getRight()->getHeight() + 1;
        }
        return 0;
    }

    //section done by Dylan
    //thanks to Guru99 for helping
    /*
     One of the things that Guru99 does that helped me was the way they delete the node. They accomplish this by copying
     data from lower level nodes upward until it reaches the bottom node and then deletes the bottom node. Why this is
     helpful is because it keeps the nodes at a constant level and thus does not have to adjust individual node's height
     value. The way I would have tried to do this on my own would be to delete the node itself and then adjust the
     pointers, however this messes up the height values of the nodes and would require going through the entire tree
     fixing height values. This strategy is also helpful for doing the rotations.
     */

     //Helper functions for balancing

    int getBalanceFactor(AVLNode<T>* node) {
        int factor = 0;

        if (node->getLeft() != nullptr && node->getRight() != nullptr) {
            factor = node->getLeft()->getHeight() - node->getRight()->getHeight();
        }
        else if (node->getLeft() != nullptr && node->getRight() == nullptr) {
            factor = node->getLeft()->getHeight();
        }
        else if (node->getLeft() == nullptr && node->getRight() != nullptr) {
            factor = 0 - node->getRight()->getHeight();
        }
        return factor;
    }

    //Helper functions to do the 4 types of rotations. Should copy data over from one node to another. Does not affect height
    //Each function returns the original node being rotated to it's new location.

    //single rotation
    AVLNode<T>* leftRotation(AVLNode<T>* node) {
        //set up the pointers
        AVLNode<T>* fromPtr;
        AVLNode<T>* toPtr;
        fromPtr = node;
        toPtr = node->getLeft();

        //do the rotation
        fromPtr->setLeft(toPtr->getRight());
        toPtr->setRight(fromPtr);
        return toPtr;
    }

    AVLNode<T>* rightRotation(AVLNode<T>* node) {
        AVLNode<T>* fromPtr;
        AVLNode<T>* toPtr;
        fromPtr = node;
        toPtr = node->getRight();

        fromPtr->setRight(toPtr->getLeft());
        toPtr->setLeft(fromPtr);
        return toPtr;
    }

    //double rotation- uses two to pointers since we move two nodes. To pointer 2 holds the final location.
    AVLNode<T>* lrRotation(AVLNode<T>* node) {
        AVLNode<T>* fromPtr;
        AVLNode<T>* toPtr;
        AVLNode<T>* toPtr2;
        fromPtr = node;
        toPtr = node->getRight();
        toPtr2 = node->getRight()->getLeft();

        fromPtr->setRight(toPtr2->getLeft());
        toPtr->setLeft(toPtr2->getRight());
        toPtr2->setLeft(fromPtr);
        toPtr2->setRight(toPtr);
        return toPtr2;
    }

    AVLNode<T>* rlRotation(AVLNode<T>* node) {
        AVLNode<T>* fromPtr;
        AVLNode<T>* toPtr;
        AVLNode<T>* toPtr2;
        fromPtr = node;
        toPtr = node->getLeft();
        toPtr2 = node->getLeft()->getRight();

        fromPtr->setLeft(toPtr2->getLeft());
        toPtr->setRight(toPtr2->getLeft());
        toPtr2->setRight(fromPtr);
        toPtr2->setLeft(toPtr);
        return toPtr2;
    }
    //notice how the two different types of rotations function identically, simply swapping left or right in each case.


    //Deletion functions

    void remove(T toDelete) {
        root = removeHelp(root, toDelete);
    }

    AVLNode<T>* removeHelp(AVLNode<T>* current, T toDelete) {
        // if what we want to delete is a leaf node or the node we want to delete was not found:
        if (current->getLeft() == nullptr && current->getRight() == nullptr) {
            if (toDelete == current->getPayload()) {
                // delete if this is the right node, do nothing otherwise
                if (current == root) {
                    root = nullptr;
                }
                delete current;
                current = nullptr;
            }
        }

        else {
            AVLNode<T>* tempPtr;
            if (current->getPayload() < toDelete) {
                current->setRight(removeHelp(current->getRight(), toDelete));
            }
            else if (current->getPayload() > toDelete) {
                current->setLeft(removeHelp(current->getLeft(), toDelete));
            }
            else {
                //move the data upward once deleted, we are on the node we want to find
                if (current->getLeft() != nullptr) {
                    tempPtr = inpre(current->getLeft());
                    current->setPayload(tempPtr->getPayload());
                    current->setLeft(removeHelp(current->getLeft(), tempPtr->getPayload()));
                }
                else {
                    tempPtr = insuc(current->getRight());
                    current->setPayload(tempPtr->getPayload());
                    current->setRight(removeHelp(current->getRight(), tempPtr->getPayload()));
                }
            }

            //Rotations to balance tree
            if (getBalanceFactor(current) == 2 & getBalanceFactor(current->getLeft()) == 1) {
                current = lrRotation(current);
            }
            else if (getBalanceFactor(current) == 2 & getBalanceFactor(current->getLeft()) == -1) {
                current = leftRotation(current);
            }
            else if (getBalanceFactor(current) == 2 & getBalanceFactor(current->getLeft()) == 0) {
                current = leftRotation(current);
            }
            //rightside
            else if (getBalanceFactor(current) == -2 & getBalanceFactor(current->getLeft()) == -1) {
                current = rightRotation(current);
            }
            else if (getBalanceFactor(current) == -2 & getBalanceFactor(current->getLeft()) == 1) {
                current = rlRotation(current);
            }
            else if (getBalanceFactor(current) == -2 & getBalanceFactor(current->getLeft()) == 0) {
                current = leftRotation(current);
            }
        }

        return current;
    }

    //Helpers for delete:
    AVLNode<T>* inpre(AVLNode<T>* current) {
        while (current->getRight() != nullptr) {
            current = current->getRight();
        }
        return current;
    }

    AVLNode<T>* insuc(AVLNode<T>* current) {
        while (current->getLeft() != nullptr) {
            current = current->getLeft();
        }
        return current;
    }



    void clearTree(AVLNode<T>* current) {
        if (current->getLeft() != nullptr) {
            clearTree(current->getLeft());
        }
        if (current->getRight() != nullptr) {
            clearTree(current->getRight());
        }
        delete current;
    }

    //Height functions

  /*  int height() {
        int height = 0;
        if (root != nullptr) {
            heightHelp(root, height);
        }
        return height;
    }

    int heightHelp(AVLNode<T>* current, int height) {

        if (current != nullptr) {
            if (current->getHeight() > height) {
                height = current->getHeight();
            }

            heightHelp(current->getLeft());
            heightHelp(current->getRight());

        }
        return height;
    }*/

    //second attempt
    /*int height() {
        int height = 0;
        if (root != nullptr) {
            heightHelp(root, height, 0, 0);
        }
        return height;
    }*/

    //int heightHelp(AVLNode<T>* current, int height, int leftCount, int rightCount) {
    //    if (current->getLeft() == nullptr && current->getRight() == nullptr) {
    //        height = leftCount + rightCount;
    //    }
    //    int tempValue = 0;
    //    //this should travel down every path and keep track of how many times a left path was taken or a right path
    //    //was taken. We can add those two numbers up to find the height of the tree. The largest path to the bottom is
    //    // the height value to save.
    //    if (current->getLeft() != nullptr) {
    //        tempValue = heightHelp(current->getLeft(), height, leftCount + 1, rightCount);
    //        if (tempValue > height) {
    //            height = tempValue;
    //        }
    //    }
    //    if (current->getRight() != nullptr) {
    //        tempValue = heightHelp(current->getRight(), height, leftCount, rightCount + 1);
    //        if (tempValue > height) {
    //            height = tempValue;
    //        }
    //    }

    //    return height;
    //}

    //third attempt
    int height() {
        cout << "height of RandomOrder AVLTree = " << heightHelper(root) << endl;
        return 0;
    }

    int heightHelper(AVLNode<T>* root) {
        if (root == NULL)
            return 0;
        else
            return max(heightHelper(root->getLeft()), heightHelper(root->getRight())) + 1;
    }

    bool contains(const T toFind) {
        return containsHelp(root, toFind);
    }

    bool containsHelp(AVLNode<T>* current, const T toFind) {
        bool result = false;
        if (current != nullptr) {
            if (toFind == current->getPayload()) {
                result = true;
            }
            else if (toFind < current->getPayload()) {
                result = containsHelp(current->getLeft(), toFind);
            }
            else if (toFind > current->getPayload()) {
                result = containsHelp(current->getRight(), toFind);
            }
        }

        return result;
    }

    //Destroy!
    ~AVLTree() {
        clearTree(root);
    }
};
