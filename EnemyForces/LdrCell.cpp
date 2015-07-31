/*
    LdrCell.cpp
    Leadership provides coordination for all subordinate cell activity and 
    with higher elements.
*/
#include <iostream>
#include "LdrCell.h"

LdrCell::LdrCell(int n, int pwr):Cell(n, ldr, 5, pwr), supplies(100), leader(true), supplier(true){}

LdrCell::LdrCell(int n, int pwr, int higher):Cell(n, ldr, 5, pwr, higher), supplies(100), leader(true), supplier(true){}

void LdrCell::buildLdrC2(std::vector<Cell*> const &subUnits, std::vector<Cell*> const &staff){
    int n = subUnits.size();
    for(int i = 0; i < n; i++)
        subCells[i] = subUnits[i];

    for(int j = 0; j < 4; j++)
        Staff[j] = staff[j];
}

bool LdrCell::HandleMessage(const Message& message){
    switch(message.Msg){
        case Msg_leader_dead:
            setLeader(false);
            return true;
        case Msg_leader_alive:
            setLeader(true);
            return true;
        case Msg_supplier_dead:
            setSupplied(false);
            return true;
        case Msg_supplier_alive:
            setSupplied(true);
            return true;
        case Msg_push_supplies:{
            std::cout << "Supplies pushed" << std::endl;
            int low = 100;
            int id = 0;
            int size = subCells.size();
            for (int i = 0; i < size; i++){
                if (subCells[i]->getSupplies() < low){
                    low = subCells[i]->getSupplies();
                    id = subCells[i]->getID();
                }
            }//end for
            if (low < 100 && id != 0)
                Commo->Send(SEND_NOW, ID, id, Msg_push_supplies, nullptr);            
            return true;
        }
        default:
            return false;
    }//end switch
}//end HandleMessage
