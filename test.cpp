#include "LineCell.h"
#include "LogCell.h"
#include "LdrCell.h"
#include "SctCell.h"
#include "MedCell.h"
#include <iostream>

int main() {
    std::cout << "\nTesting line cell:" << std::endl;
    LineCell a(1, 1, 1, 1, true, true);
    std::cout << "Type: " << a.cellName[a.getType()] << std::endl;
    std::cout << "Power: " << a.getPower() << std::endl;
    std::cout << "Leader? " << a.hasLeader() << std::endl;
    std::cout << "Supplied? " << a.isSupplied() << std::endl;
    std::cout << "\nKilling leader and supplier\n" << std::endl;
    a.setLeader(false);
    a.setSupplied(false);
    std::cout << "Leader? " << a.hasLeader() << std::endl;
    std::cout << "Supplied? " << a.isSupplied() << std::endl;

    std::cout << "\nTesting leader cell:" << std::endl;
    LdrCell b(1, 1, 1, 1, true, true);
    std::cout << "Type: " << b.cellName[b.getType()] << std::endl;
    std::cout << "Power: " << b.getPower() << std::endl;
    std::cout << "Leader? " << b.hasLeader() << std::endl;
    std::cout << "Supplied? " << b.isSupplied() << std::endl;
    std::cout << "\nKilling leader and supplier\n" << std::endl;
    b.setLeader(false);
    b.setSupplied(false);
    std::cout << "Leader? " << b.hasLeader() << std::endl;
    std::cout << "Supplied? " << b.isSupplied() << std::endl;

    std::cout << "\nTesting log cell:" << std::endl;
    LogCell c(1, 1, 1, 1, true, true);
    std::cout << "Type: " << c.cellName[c.getType()] << std::endl;
    std::cout << "Power: " << c.getPower() << std::endl;
    std::cout << "Leader? " << c.hasLeader() << std::endl;
    std::cout << "Supplied? " << c.isSupplied() << std::endl;
    std::cout << "\nKilling leader and supplier\n" << std::endl;
    c.setLeader(false);
    c.setSupplied(false);
    std::cout << "Leader? " << c.hasLeader() << std::endl;
    std::cout << "Supplied? " << c.isSupplied() << std::endl;

    std::cout << "\nTesting scout cell:" << std::endl;
    SctCell d(1, 1, 1);
    std::cout << "Type: " << d.cellName[d.getType()] << std::endl;
    std::cout << "Power: " << d.getPower() << std::endl;

    std::cout << "\nTesting med cell:" << std::endl;
    MedCell e(1, 1, 1, 1);
    std::cout << "Type: " << e.cellName[e.getType()] << std::endl;
    std::cout << "Power: " << e.getPower() << std::endl;

    std::cout << std::endl;

}
