/*
 *  EntityManager.cpp
 *
 */

#include "EntityManager.h"
#include <memory>

EntityManager* EntityManager::Instance() {
    static EntityManager instance;
    return &instance;
}

//add Cell to hash table
void EntityManager::RegisterEntity(Cell* newCell){
   entityMap.addItem(newCell->getID(), newCell); 
}

//remove cell from hash table, given a pointer to the cell
void EntityManager::RemoveEntity(Cell* rCell) {
    entityMap.removeItem(rCell->getID());
}

//remove cell from hash table, given the cell's ID
void EntityManager::RemoveEntity(int id) {
    entityMap.removeItem(id);
}

//get a pointer to a cell
Cell* EntityManager::GetEntityFromID(int id) {
    return entityMap.getObj(id);    
}

//print out every registered entity
void EntityManager::ListAll(){
    entityMap.listAll();
}

//remove all entities from the hash table
void EntityManager::RemoveAll(){
    entityMap.removeAll();
}

