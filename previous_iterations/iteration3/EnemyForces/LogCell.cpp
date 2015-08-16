/*
    LogCell.cpp
    The logistics cells supplies materiel to the line cells at a faster rate 
    then they would otherwise be supplied.
*/
#include <iostream>
#include <ctime>
#include "LogCell.h"

LogCell::LogCell(int n, int pwr):Cell(n, logistics, 5, pwr), supplies(100), leader(true), supplier(true){}

LogCell::LogCell(int n, int pwr, int higher):Cell(n, logistics, 5, pwr, higher), supplies(100), leader(true), supplier(true){}

bool LogCell::event(int chance){
    randNum = rand() % 9 + 1;
    //return false if unable to conduct operations
    //if(!leader || supplies < 33 || members < 3 || randNum < chance) {
    if(randNum < chance) {
        //if unable to conduct ops, and logistics available, then resupply
        //if(supplies < 33 && isSupplied())
        //    supplies += 10;        
        //if (isSupplied())
            //supplies += 10;
        //std::cout << cellName[cType] << " cell " << ID << " is not pushing supplies." << std::endl;
        return false;
    }

    //supplies -= 30;
    std::cout << cellName[cType] << " cell " << ID << " is pushing supplies." << std::endl;
    Commo->Send(SEND_NOW, ID, higherID, Msg_push_supplies, nullptr);
    return true;

}//end event

bool LogCell::HandleMessage(const Message& message){
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
        default:
            return false;
    }//end switch
}//end HandleMessage
