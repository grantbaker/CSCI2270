#include "HashTable.h"

HashTable::HashTable(int n) {
    HashTable::tableSize = n;
    HashTable::ht = new HashVector[n];
}

HashTable::~HashTable() {
    //dtor
}

void HashTable::insertMovie(std::string name, int year) {
    int index = HashTable::hashSum(name, HashTable::tableSize);
    HashTable::ht[index].v.push_back(new HashElem(name, year));
}

void HashTable::deleteMovie(std::string name) {
    int index = HashTable::hashSum(name, HashTable::tableSize);
    int i;
    for (i=0; i<HashTable::ht[index].v.size(); i++) {
        if (HashTable::ht[index].v[i]->title.compare(name) == 0) {
            HashTable::ht[index].v.erase(HashTable::ht[index].v.begin()+i);
            break;
        }
    }
}

void HashTable::findMovie(std::string name) {
    int index = HashTable::hashSum(name, HashTable::tableSize);
    int i;
    HashElem* tmp = NULL;
    for (i=0; i<HashTable::ht[index].v.size(); i++) {
        if (HashTable::ht[index].v[i]->title.compare(name) == 0) {
            tmp = HashTable::ht[index].v[i];
            break;
        }
    }
    if (tmp) {
        std::cout<<index<<":"<<tmp->title<<":"<<tmp->year<<std::endl;
    } else {
        std::cout<<"not found"<<std::endl;
    }
}

void HashTable::printTableContents() {
    int i,j;
    bool exist = false;
    for (i=0; i<HashTable::tableSize; i++) {
        for (j=0; j<HashTable::ht[i].v.size(); j++) {
            exist = true;
            std::cout<<HashTable::ht[i].v[j]->title<<":"<<HashTable::ht[i].v[j]->year<<std::endl;
        }
    }
    if (!exist) {
        std::cout<<"empty"<<std::endl;
    }
}

int HashTable::hashSum(std::string x, int s) {
    int sum = 0;
    int i = 0;
    while (i!=x.length()) {
        sum += x[i];
        i++;
    }
    return sum%s;
}
