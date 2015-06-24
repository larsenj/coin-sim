#ifndef CELLS_H
#define CELLS_H

enum cell { line, ldr, log, sct, med };

class Cells {
    protected:
        int ID;
        int members;
        int randNum;
        cell cellType;
        int power;
        int wCount = 0;
    public:
        Cells();
        Cells(int);
        Cells(int, cell, int, int);
        bool event(int);
        const char* cellName[5] = { "line", "ldr", "log", "scout", "med" };
        inline cell getType() { return cellType;}
        inline int getWeekCount() { return wCount; }
        inline int getPower() { return power; }
        inline int getID() { return ID; }

};

#endif
