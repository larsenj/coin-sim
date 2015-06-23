#include "LineCell.h"
#include <iostream>

int main() {
    LineCell a(1, 1, 1, 1, true, true);
    std::cout << "Type: " << a.getType() << std::endl;
    std::cout << "Power: " << a.getPower() << std::endl;
    std::cout << "Leader? " << a.hasLeader() << std::endl;
    std::cout << "Supplied? " << a.isSupplied() << std::endl;
    std::cout << "\nKilling leader and supplier\n" << std::endl;
    a.setLeader(false);
    a.setSupplied(false);
    std::cout << "Leader? " << a.hasLeader() << std::endl;
    std::cout << "Supplied? " << a.isSupplied() << std::endl;
}
