#include "EntityManager.h"
#include <memory>

EntityManager* EntityManager::Instance() {
    static EntityManager instance;
    return &instance;
}

void EntityManager::RegisterEntity(Cell* newCell){
   entityMap.addItem(newCell->getID(), newCell); 
}

void EntityManager::RemoveEntity(Cell* rCell) {
    entityMap.removeItem(rCell->getID());
}

void EntityManager::RemoveEntity(int id) {
    entityMap.removeItem(id);
}

Cell* EntityManager::GetEntityFromID(int id) {
    return entityMap.getObj(id);    
}
    
