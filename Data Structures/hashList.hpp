#pragma once

#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class HashTable{
    private:
    static const int hashGroup = 10;
    list<pair<int, string>> table[hashGroup];

    public:
    bool isEmpty() const;
    int hash(int key);
    void insert(int key, string value);
    void remove(int key);
    string search(int key);
    void printTable();
};

bool HashTable :: isEmpty() const{
    
    int sum{};

    for (int i = 0; i < hashGroup; i++)
    {
        sum += table[i].size();
    }

    if (!sum)
    {
        return true;
    }

    return false;
}

int HashTable :: hash(int key){

    return key % hashGroup;
}

void HashTable :: insert(int key, string value){

    int hashValue = hash(key);
    auto &cell = table[hashValue];
    auto bIterator = begin(cell);
    bool keyExist = false;

    for (; bIterator != end(cell); bIterator++)
    {
        if (bIterator->first == key)
        {
            keyExist = true;
            bIterator->second = value;

            cout << "[WARNING] Key Is Existing. Value Has Been Replaced\n";
            break;
        }
    }

    if (!keyExist)
    {
        cell.push_back(key, value);
    }
}

void HashTable :: remove(int key){

    int hashValue = hash(key);
    auto &cell = table[hashValue];
    auto bIterator = begin(cell);
    bool keyExist = false;

    for (; bIterator != end(cell); bIterator++)
    {
        if (bIterator->first == key)
        {
            keyExist = true;
            bIterator = cell.erase(bIterator);

            cout << "[Information] Key Pair Has Been Removed\n";
            break;
        }
    }

    if (!keyExist)
    {
        cout << "[WARNING] Key Pair Not Found\n";
    }
}

void HashTable :: printTable(){

    for (int i = 0; i < hashGroup; i++)
    {
        if (table[i].size() == 0)
        {
            continue;
        }

        auto bIterator = table[i].begin();

        for (; bIterator != table[i].end(); bIterator++)
        {
            cout << "[Information] Key: " << bIterator->first << " Value: " << bIterator->second << "\n";
        }
    }
}