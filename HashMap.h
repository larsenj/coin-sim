#ifndef HASHMAP_H
#define HASHMAP_H

#include <cstddef>

template <typename T>
class HashMap {
    private:
        static const int tableSize = 17;
        struct item{
            int id;
            T* object; //maybe make std::shared_ptr<K>
            item* next; 
        };
        item* HashTable[tableSize];

    public:
        HashMap();
        int hash(int id);
        void addItem(int id, T* object);
        int numItemsInIndex(int);
        T* getObj(int);
        int removeItem(int);
        void listAll();
};


#endif
