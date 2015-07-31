/*
    LogCell.cpp
    The logistics cells supplies materiel to the line cells at a faster rate 
    then they would otherwise be supplied.
*/

#ifndef LOGCELL_H
#define LOGCELL_H

#include "Cell.h"
#include "../Message.h"
#include "../CommoNet.h"

class LogCell:public Cell {
    private:
        int supplies;
        bool leader;
        bool supplier;

    public:
        LogCell();
        LogCell(int, int);
        LogCell(int, int, int);
        bool HandleMessage(const Message&);
        bool event(int);
        inline bool hasLeader() { return leader; }
        inline void setLeader(bool ldr) { leader = ldr; }
        inline bool isSupplied() { return supplier; }
        inline void setSupplied(bool sup) { supplier = sup; }
};

#endif
