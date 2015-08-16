/*
    HashMap.h
    Hash table to store pointers to objects(cells), with integers(id) as keys
*/

#ifndef HASHMAP_H
#define HASHMAP_H

#include<memory>

template <typename T>
class HashMap {
    private:
        static const int tableSize = 17;
        struct item{
            int id;
            T* object; //maybe make std::shared_ptr<T>
            item* next; 
        };
        item* HashTable[tableSize];

    public:
        HashMap();
        int hash(int);
        void addItem(int, T*);
        int numItemsInIndex(int);
        T* getObj(int);
        int removeItem(int);
        void listAll();
        void removeAll();
};


#endif
