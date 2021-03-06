/*
    EntityManager.h
    Used to register and track all Cells. ID, pointer pair stored in the
    hash table.
*/

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "HashMap.h"
#include "EnemyForces/Cell.h"
#include <memory>

class EntityManager {
    private:
        HashMap<Cell> entityMap;
        EntityManager(){}


    public:
        //singleton
        static EntityManager* Instance();
        void RegisterEntity(Cell* newCell);
        void RemoveEntity(Cell* rCell);
        void RemoveEntity(int id);
        Cell* GetEntityFromID(int id);
        void ListAll();
        void RemoveAll();
};

#define EntityMgr EntityManager::Instance()

#endif
