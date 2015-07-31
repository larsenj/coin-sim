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
#include "EnemyForces/GhkCo.h"

class Province {
    private:
        std::vector<std::unique_ptr<GhkCo>> efVector;//holds all Companies of the Province
        int wCount; //stores total number of SIGACTS for the week
        int ID; //first digit of number represents this province
        int daySIG[7];//store number of SIGACTS per day
        int stability; //indicates if province supports INS or COIN forces
    public:
        std::string name;
        Province(){};
        Province(std::string); //name
        Province(std::string, int, int); //name, id, companies
        Province(std::string, int, int, int); //name, id, companies, stability
        inline int getWeekCount() { return wCount; }
        inline int getID() { return ID; }
        inline std::string getName() { return name; }
        inline int getDaySig(int day) { return daySIG[day]; }
        inline void setStability(int s) {stability = s;}
        inline int getStability() {return stability;}
        //increase pro-COIN sentiment/decrease INS support
        inline void upStability(int n) {
            if (stability < 100) stability += n;
            if (stability > 100) stability = 100;
        }
        //decrease pro-COIN sentiment/increase INS support
        inline void downStability(int n) {
            if (stability > 0) stability -= n;
            if (stability < 0) stability = 0;
        }
        void weekEvents(); //runs the weekEvents function for all subordinates
        ~Province(){}
};

#endif
