/*
    Province.h
    Represents a politically demarcated piece of terrain. May contain any number
    of districts.
    FF will operate here at the BN level.
*/

#ifndef PROVINCE_H
#define PROVINCE_H

#include <string>
#include <vector>
#include <memory>
#include "GhkCo.h"

class Province {
    private:
        std::vector<std::unique_ptr<GhkCo>> efVector;//holds all Companies of the Province
        int wCount; //stores total number of SIGACTS for the week
        int ID; //first digit of number represents this province
    public:
        std::string name;
        Province(){};
        Province(std::string); //name
        Province(std::string, int, int); //name, id, companies
        inline int getWeekCount() { return wCount; }
        inline int getID() { return ID; }
        inline std::string getName() { return name; }
        void weekEvents(); //runs the weekEvents function for all subordinates
        ~Province(){}
};

#endif
