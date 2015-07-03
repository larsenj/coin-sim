/*
    LdrCell.cpp
    Leadership provides coordination for all subordinate cell activity and 
    with higher elements.
*/
#include <iostream>
#include "LdrCell.h"

LdrCell::LdrCell(int n, int num, int pwr, int stock, bool lead, bool sup):Cell(n, ldr, num, pwr), supplies(stock), leader(lead), supplier(sup){}



