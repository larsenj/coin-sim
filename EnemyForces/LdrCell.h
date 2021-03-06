/*
    LdrCell.h
    Leadership provides coordination for all subordinate cell activity and 
    with higher elements.
*/

#ifndef LDRCELL_H
#define LDRCELL_H

#include <vector>
#include "Cell.h"
#include "../CommoNet.h"

class LdrCell:public Cell {
    private:
        int supplies;
        bool leader;
        bool supplier;
        std::vector<Cell*> subCells;
        Cell* Staff[4];
    public:
        LdrCell();
        LdrCell(int, int);
        LdrCell(int, int, int);//ID, pwr, higher
        bool HandleMessage(const Message&);
        void buildLdrC2(std::vector<Cell*> const &subUnits, std::vector<Cell*> const &staff);
        inline bool hasLeader() { return leader; }
        inline bool setLeader(bool ldr) { leader = ldr; }
        inline bool isSupplied() { return supplier; }
        inline bool setSupplied(bool sup) { supplier = sup; }
};

#endif
