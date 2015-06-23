#ifndef PROVINCE_H
#define PROVINCE_H

#include <string>
#include <vector>
#include "Cells.h"

class Province {
    private:
        std::vector<Cells> cellVector;//holds all Cells of the Province
        int daySIG[7]; //holds number of SIGACTS per day per week
        int wCount; //stores total number of SIGACTS for the week
    public:
        std::string name;
        Province();
        Province(std::string);
        Province(std::string, int);
        inline int getWeekCount() { return wCount; }
        int dayEvents();
        void weekEvents();
        void weekRollup();
};

#endif
