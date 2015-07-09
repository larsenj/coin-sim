#include "Province.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
//#include <stdio.h>

//using namespace std;

Province::Province(){}//default constructor

Province::Province(std::string pName) : name(pName)
{
   // name = pName;
}//end constructor

//this will have to change to accomodate for differing types of cells
Province::Province(std::string pName, int nCells){
    name = pName;
    //populate Cells vector
    for(int i = 0; i < nCells; i++){
        cellVector.push_back(Cells(i, 5, 100));    
    }
}//end constructor

/*int Province::getWeekCount(){
    return wCount;
}//end getWeekCount */

//determine how many cells have SIGACTS for the day
int Province::dayEvents(){
    int numCells = cellVector.size();
    int count = 0;
    
    for (int i = 0; i < numCells; i++) {
        if(cellVector[i].event()){
            count++;
        }
    }
    return count;
}//end dayEvents

//run the week, determining how many SIGACTS happened
void Province::weekEvents(){
    wCount = 0;
    int numCells = cellVector.size();

    //count SIGACTS for the week
    int dCount;
    for(int i = 0; i < 7; i++){
        dCount = 0;

        //count SIGACTS for the day
        for (int j = 0; j < numCells; j++){    
            dCount += dayEvents();
        }

        daySIG[i] = dCount;        
        wCount += dCount; //add the day's count to the running total
    }
}//end weekEvents

//output the results of the week
void Province::weekRollup() {
    std::cout << name << ":" << std::endl;
    for (int i = 0; i < 7; i++)
        std::cout << "On day " << i+1 << " there were " << daySIG[i] << " SIGACTS" << std::endl; 
}//end weekRollup




