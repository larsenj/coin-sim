#ifndef CELL_H
#define CELL_H

enum CellType { line, ldr, log, sct, med };

class Cell {
    protected:
        int ID;
        int members;
        int randNum;
        CellType cType;
        int power;
        int wCount = 0;
    public:
        Cell();
        Cell(int);
        Cell(int, CellType, int, int);
        bool event(int);
        const char* cellName[5] = { "line", "ldr", "log", "scout", "med" };
        inline CellType getType() { return cType;}
        inline int getWeekCount() { return wCount; }
        inline int getPower() { return power; }
        inline int getID() { return ID; }
        ~Cell();
};

#endif
