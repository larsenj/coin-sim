/*
    LogCell.cpp
    The logistics cells supplies materiel to the line cells at a faster rate 
    then they would otherwise be supplied.
*/
#include <iostream>
#include "LogCell.h"

LogCell::LogCell(int n, int pwr):Cell(n, log, 5, pwr), supplies(100), leader(true), supplier(true){}

LogCell::LogCell(int n, int pwr, int higher):Cell(n, log, 5, pwr, higher), supplies(100), leader(true), supplier(true){}


