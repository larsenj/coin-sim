/**
    LineCell.cpp
    This is your basic frontline cell. Currently it will be used
    for all SIGACTS
*/
#include <iostream>
#include "LineCell.h"

LineCell::LineCell(int n, int pwr):Cell(n, line, 5, pwr), supplies(100), leader(true), supplier(true){
//    std::cout<<"Creating LineCell " << n << std::endl;
}

LineCell::LineCell(int n, int pwr, int higher):Cell(n, line, 5, pwr, higher), 
    supplies(100), leader(true), supplier(true){
//    std::cout<<"Creating LineCell " << n << std::endl;
}

bool LineCell::HandleMessage(const Message& message){
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
        case Msg_push_supplies:
            supplies += 50;
            std::cout << "Got a resupply!" << std::endl;
            return true;
        default:
            return false;
    }//end switch
}//end HandleMessage

