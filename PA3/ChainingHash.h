/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    float numElements = 0;
    const float loadLimit = 0.75;
    float tableSize = 101;
    //int numBucks;
    vector<list<pair<K,V>>> * table;

public:
    //constructor
    //used vector resizing code from cpluplus.com as an example
    //for inspiration throughout the project.
    ChainingHash(int n = 11) {
        list<pair<K,V>> pairList;
        table = new vector<list<pair<K,V>>>;
        table->resize(n, pairList);
        tableSize = n;
    }

    //destructor
    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return numElements;
    }

    V operator[](const K& key) {
       /* V result = 0;
        //go to the bucket where the data should be
        int search = hash(key);

        // search through the bucket until you reach the end or find the data
        for (int i = 0; i < table->at(search).size(); i++) {
            if (key == table->at(search)->at(i).first) {
                result = table->at(search)->at(i).second;
            }
        }*/
       //attempt 2
       V result = 0;
       int where = hash(key);
       list<std::pair<K,V>> whichList = table->at(where);

       //iteration thru list
        for (auto& item : whichList) {
            if (item.first == key){
                result == item.second;
            }
        }
        return result;
    }


    bool insert(const std::pair<K, V>& pair) {
        int key = hash(pair.first);
        this->erase(pair.first);
        ++numElements;
        table->at(key).push_front(pair);

        //rehash check
        if (load_factor() > loadLimit)
        {
            rehash();
        }
        return true;
    }

    void erase(const K& key) {
        /*//go to the bucket to we need to delete from
        int search = hash(key);

        // search through the bucket until you reach the end or find the data
        for (int i = 0; i < table->at(search).size(); i++) {
            if (key == table->at(search)->at(i).first) {
                table->at(search)->erase(i);
            }
        }*/

        //attempt 2
        int where = hash(key);
        list<std::pair<K, V>> whichList = table->at(where);

        //iteration thru list
        for (auto& item : whichList)
        {
            if (item.first == key)
            {
                whichList.remove(item);
            }
        }
    }

    void clear() {
        for (int i = 0; i < table->size(); i++) {
            table[i].clear();
        }
        numElements = 0;
    }

    int bucket_count() {
        return tableSize;
    }

    float load_factor() {
        if (tableSize == 0){
            return 0;
        }
        else {
            float result = (numElements / tableSize);
            cout << result << endl;
            return (numElements / tableSize);
        }
    }

    //used rehash examples from stackoverflow.com/questions/20037963/rehashing-a-table
    //as inspiration to create rehash for chaining and probing
    void rehash()
    {
        //create new list
        list<pair<K,V>> newList;
        //new vector
        vector<list<pair<K,V>>> newVector = std::move(*table);
        //resize table
        table->resize(findNextPrime(table->capacity()), newList);
        //make for loop to insert into new vector
        for (int i = 0; i < newVector.capacity(); i++) {
            //empty checker
            numElements = 0;
            while(newVector[i].empty() == false) {
                insert(newVector[i].front());
                newVector[i].pop_front();
            }
        }
    }

private:

    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return (key % table->capacity());
    }

};

#endif //__CHAINING_HASH_H