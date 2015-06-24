/*
    LogCell.cpp
    The logistics cells supplies materiel to the line cells at a faster rate 
    then they would otherwise be supplied.
*/

#ifndef LOGCELL_H
#define LOGCELL_H

#include "Cells.h"

class LogCell:public Cells {
    private:
        int supplies;
        bool leader;
        bool supplier;

    public:
        LogCell();
        LogCell(int, int, int, int, bool, bool);
        inline bool hasLeader() { return leader; }
        inline bool setLeader(bool ldr) { leader = ldr; }
        inline bool isSupplied() { return supplier; }
        inline bool setSupplied(bool sup) { supplier = sup; }
        ~LogCell();
};

#endif
