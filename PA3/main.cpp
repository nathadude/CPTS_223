#include <map>
#include <string>
#include <chrono>
#include <cassert>
#include "ChainingHash.h"
#include "ProbingHash.h"

void testHash(Hash<int, int> *hash) {

    std::cout << "current size: " << hash->size() << " bucket count: " << hash->bucket_count()
              << " load factor: " << hash->load_factor() << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 100000; ++i) {
        assert(hash->insert(std::make_pair(i, i)));
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    assert((*hash)[97] == 97);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    hash->erase(97);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    assert((*hash)[10000] == 10000);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "current size: " << hash->size() << " bucket count: " << hash->bucket_count()
              << " load factor: " << hash->load_factor() << std::endl;
    hash->clear();
}

int main(int argc, char* argv[])
{
    ChainingHash<int, int> cHash(101);
    testHash(&cHash);

    ProbingHash<int, int> pHash(101);
    testHash(&pHash);
}
