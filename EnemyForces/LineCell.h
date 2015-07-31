#ifndef LINECELL_H
#define LINECELL_H

#include <iostream>
#include "Cell.h"
#include "../Message.h" 

class LineCell:public Cell {
    private:
        int supplies;
        bool leader;
        bool supplier;
    public:
        LineCell();
        LineCell(int, int);
        LineCell(int, int, int);//ID,pwr,higher
        bool HandleMessage(const Message&);
        inline bool hasLeader() { return leader; }
        inline void setLeader(bool ldr) { leader = ldr; }
        inline bool isSupplied() { return supplier; }
        inline void setSupplied(bool sup) { supplier = sup; }
        inline int getSupplies() { return supplies; }
};

#endif
