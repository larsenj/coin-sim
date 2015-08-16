/*
    HashMap.cpp
*/

#include <cstddef>
#include <iostream>
#include "HashMap.h"
#include "EnemyForces/Cell.h"

template<typename T>
HashMap<T>::HashMap(){
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new item;
        HashTable[i]->id = 0;
        HashTable[i]->object = NULL;
        HashTable[i]->next = NULL;
    }
}

template<typename T>
int HashMap<T>::hash(int id){
    int index;
    int hash = 0;
    int i;
    if (id/10000000 == 1)
        i = 10000000;
    //in case of double-digit province id
    else
        i = 100000000;
    //add each digit in the id number
    for (i ; i >=1 ; i /= 10){
        hash += id/i;
        id %= i;
    }
    
    return hash % tableSize;
}

//add an item with given id as key, and pointer as obj
template<typename T>
void HashMap<T>::addItem(int id, T* object){
    int index = hash(id);
    //if the first entry at that index is the default
    if (HashTable[index]->id == 0){
        HashTable[index]->id = id;
        HashTable[index]->object = object;
    }
    //if there is an existing entry at that index
    else{
        item* ptr = HashTable[index];
        item* n = new item;
        n->id = id;
        n->object = object;
        //find the end of the line
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = n;
    }
}

//return a pointer to object in item with given id
template<typename T>
T* HashMap<T>::getObj(int id){
    //find the index
    int index = hash(id);

    item* ptr = HashTable[index];

    if (ptr->id == id)
        return ptr->object;
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
            if(ptr->id == id)
                return ptr->object;
        }//end while
    }//end else
    
    return NULL; //if object not found
}//end getObj

//Remove the item with the given id key. Returns 1
//if not item with that key
template<typename T>
int HashMap<T>::removeItem(int id){
    //find the index
    int index = hash(id);
    //if the index is empty
    if (HashTable[index]->id == 0)
        return 1; //nothing at that index
    item* ptr = HashTable[index];
    //if the index is the id
    if (ptr->id == id)
    {
        if (ptr->next == NULL)
        {
            ptr->id = 0;
            ptr->object = NULL;
            return 0;
        }
        else
        {
            ptr = ptr->next;
            return 0;
        }
    }
    //if the index is not empty, but isn't the id
    if (HashTable[index]->id != id){
        while (ptr->next != NULL){
            ptr = ptr->next;
            if(ptr->id == id){ 
                if (ptr->next == NULL){
                    ptr->id = 0;
                    ptr->object = NULL;
                    return 0;
                }
                else{
                    ptr = ptr->next;
                    return 0;
                }
            }
        }//end while
    }
    return 1;
}

//list number of items at a given index
template<typename T>
int HashMap<T>::numItemsInIndex(int index){
    if (index > tableSize)
        return 0;
    int count = 0;
    //index is empty
    if (HashTable[index]->id == 0)
        return 0;
    //index has 1 item
    else if (HashTable[index]->next == NULL)
        return 1;
    //index has > 1 item
    else{
        item* ptr = HashTable[index];
        while (ptr->next != NULL){
            count++;
            ptr = ptr->next;
        }
        count++;
    }
    return count;
}

//list all keys in the table
template<typename T>
void HashMap<T>::listAll(){
    item* ptr=nullptr;
    for(int i = 0; i < tableSize; i++){
        std::cout << "\nIndex " << i << ":";
        ptr = HashTable[i];
        if (ptr->id != 0){
            std::cout << "\t" << ptr->id; 
            while (ptr->next != NULL){
                ptr = ptr->next;
                std::cout << "\t" << ptr->id; 
            }//end while
        }//end if
    }//end for iteration through index
    std::cout << std::endl;
}

//remove all items from table. Note: does NOT call destructors.
template<typename T>
void HashMap<T>::removeAll(){
    for (int i = 0; i < tableSize; i++)
        if (HashTable[i]->id != 0){
            HashTable[i]->id = 0;
            HashTable[i]->object = NULL;
            HashTable[i]->next = NULL;
        }
    
}


template class HashMap<Cell>;

