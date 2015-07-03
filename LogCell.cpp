/*
    LogCell.cpp
    The logistics cells supplies materiel to the line cells at a faster rate 
    then they would otherwise be supplied.
*/
#include <iostream>
#include "LogCell.h"

LogCell::LogCell(int n, int num, int pwr, int stock, bool lead, bool sup):Cell(n, log, num, pwr), supplies(stock), leader(lead), supplier(sup){}



