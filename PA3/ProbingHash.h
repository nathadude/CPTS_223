#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    float tableSize = 0;
    const float loadLimit = 0.75;
    float numElements = 0;
    struct HashEntry {
        pair<K,V> element;
        EntryState state;
    };
    vector<HashEntry> table;

public:
    //constructor

    ProbingHash(int n = 11) {
        HashEntry probeTable;
        probeTable.state = EMPTY;
        table.resize(n, probeTable);
        tableSize = n;
    }
    //destructor
    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return -1;
    }

    V operator[](const K& key) {
        //attempt 2
        int result;
        int position = getPos(key);
        if (position == -1) {
            //does not exist in table
            return -1;
        }

        if (table.at(position).state == 1) {
            result = table.at(position).element.second;
        }

        return result;
    }
        //useful for searching and deleting?
        int getPos(const K& key) {
            int offset = 1;
            int position = hash(key);
            int numAttempts = 1;

            while (table.at(position).state != EMPTY && table.at(position).element.first != key) {
                position += offset;
                offset += 1;
                if (position >= tableSize) {
                    position -= tableSize;
                }
                if (numAttempts >= tableSize) {
                    return -1;
                }
            }
            return position;
        }


        //is active function

        bool isActive(int position) const{

            if (position == -1) {
                return 0;
            }

            return table.at(position).state == VALID;
    }

    bool insert(const std::pair<K, V>& pair) {

        //first attempt: used chaining hash as reference
      /*  if (load_factor() > loadLimit){
            //rehash();
        }
        int key = hash(pair.first);
        int position = getPos(key);
        while (table.at(position).element.second == EntryState::VALID){
            if (table.at(position).element.first == pair.first){
                break;
            }
            key = probe(key);
            if (table.at(position).element.first != pair.first){
                table.at(position).element.first = pair.first;
                table.at(position).state = EntryState::VALID;
            }
        }*/
      //third attempt using code from hashing 5 slides
      int key = hash(pair.first);
      int position = getPos(key);

      if (isActive(position)){
            return false;
        }
      //table[position] = HashEntry(key, VALID);
      //table.at(position) = HashEntry(key, VALID);
      table.at(position).element.first = key;
      table.at(position).state = VALID;
      ++numElements;

      if(load_factor() > loadLimit){
          rehash();
      }
        return true;

    }

    int probe(int i){
        return ((i+1) % table.capacity());
    }

    void erase(const K& key) {
        //find the element
        int position = getPos(key);
        //Is it empty or does it not exist?
        if (!isActive(position) || position == -1) {
            //do nothing
        }
            //delete it if it is active
        else {
            table.at(position).state == 2;
        }
    }

    void clear() {
        table.clear();
        numElements = 0;
    }

    int bucket_count() {
        return tableSize;
    }

    float load_factor() {

        if (tableSize == 0) {
            //does nothing
        }
        else {
            float result = (numElements / tableSize);
            cout << result << endl;
            return (numElements / tableSize);
        }
    }

    void rehash()
    {
       /* //first attempt
        //probing rehash attempt - similar to chaining
        //use of . rather than ->
        vector<HashEntry> newVect = std::move(table);
        table.resize(findNextPrime(table.capacity()));
        //tableSize = 0;
        for (int i = 0; i < newVect.capacity(); i++) {
            //can't use push back or pop front, not using list

            insert(std::move(newVect[i].first));
        }
        table.resize(findNextPrime(table.capacity()));*/

        //second attempt using hashing 5 slides
        vector<HashEntry> oldTable = table;

        //new resized table
        table.resize(findNextPrime(2 * oldTable.size()));
        for (int i = 0; i < table.size(); i++) {
            table.at(i).state = EMPTY;
        }
        //stuck in an infinite rehash loop couldn't figure out how to get out
        numElements = 0;
        for (int j = 0; j < oldTable.size(); j++) {
            if (oldTable.at(j).state == VALID){
                numElements--;
                insert(oldTable.at(j).element);
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
        return (key % table.capacity());
    }

};

#endif //__PROBING_HASH_H