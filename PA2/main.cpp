#include <iostream>
#include "AVLTree.h"
#include "time.h"
//Nathaniel Anderson
using namespace std;

int main()
{
    //create 3 sequences

    srand(time(0));
    int A = 0, D = 0, R = 0;
    int num = 100;
    const int size = 50;
    int remainder;
    int ascending[size];
    int descending[size];
    int random[size];

    for (int i = 0; i < num; i++)
    {
        remainder = i % 2;
        if (remainder != 0)
        {
            ascending[A] = i;
            //cout << ascending[A] << endl;
            A++;
        }
    }

    for (int i = num; i > 0; i--)
    {
        remainder = i % 2;
        if (remainder != 0)
        {
            descending[D] = i;
            //cout << descending[D] << endl;
            D++;
        }
    }

    //create random array, credit profgustin, used their code as a reference
    //to implement a randomized array without std shuffle
    for (int i = 0; i < num; i++)
    {
        remainder = i % 2;
        if (remainder != 0)
        {
            random[R] = i;
            R++;
        }
    }

    for (int i = 0; i < 50; i++)
    {
        int randomIndex = rand() % 50;

        int temp = random[i];
        random[i] = random[randomIndex];
        random[randomIndex] = temp;
    }

    //random array test:it works
   /* for (int i = 0; i < 50; i++)
    {
        cout << random[i] << endl;
    }*/

    
    //create three avl trees to insert the three sequences into
    AVLTree<int>* avlA = new AVLTree<int>();

    for ( int i = 0; i < 50; i++)
    {
        avlA->insert(ascending[i]);
    }

    
    AVLTree<int>* avlD = new AVLTree<int>();

    for (int i = 0; i < 50; i++)
    {
        avlD->insert(descending[i]);
    }

    AVLTree<int>* avlR = new AVLTree<int>();

    for (int i = 0; i < 50; i++)
    {
        avlR->insert(random[i]);
    }

    //Print out the heights of all the trees
    avlA->height();
    avlD->height();
    avlR->height();

    //Validate all the trees
    avlA->validate();
    avlD->validate();
    avlR->validate();

    //run contains on all the trees
    for (int i = 0; i < 100; i++)
    {
        cout << avlA->contains(i);
        cout << avlD->contains(i);
        cout << avlR->contains(i);
    }

    delete avlA;
    delete avlD;
    delete avlR;

    return 0;
}
