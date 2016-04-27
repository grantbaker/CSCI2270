#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>
#include <algorithm>

struct HashElem {
    std::string title;
    int year;

    HashElem(){};
    HashElem(std::string in_title, int in_year) {
        title = in_title;
        year = in_year;
    }
};

struct HashVector {
    std::vector<HashElem*> v;
};

class HashTable {
    public:
        HashTable(int n);
        virtual ~HashTable();

        void insertMovie(std::string name, int year);
        void deleteMovie(std::string name);
        void findMovie(std::string name);
        void printTableContents();
    protected:
    private:
        int hashSum(std::string x, int s);

        int tableSize;
        HashVector* ht;
};

#endif // HASHTABLE_H
