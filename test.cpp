#include "CellWrapper.h"
#include "GhkGroup.h"
#include "GhkCo.h"
#include "Province.h"
#include <iostream>
#include <string>

using namespace std;

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


    std::cout << "\nTesting GhkGroup" << std::endl;
    GhkGroup ggroup(10000, 1);
    std::cout << "GhkGroup name is: " << ggroup.getID() << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << "The cell ID is: " << ggroup.getCellID(i) << std::endl;

    std::cout << "\nTesting GhkCo" << std::endl;
    GhkCo gco(1000000, 1);
    std::cout << "GhkCo name is: " << gco.getID() << std::endl;
    std::cout << "Members are:" << std::endl;
    gco.printMemberIDs();
    std::cout << "Test events" << std::endl;
    int wE = gco.weekEvents();
    std::cout << wE << " should be " << gco.getWeekEvents() << std::endl;

    std::cout << "\nTesting Province" << std::endl;
    Province p("Oz", 1, 2);
    std::cout << p.getName() << "'s ID is " << p.getID() << std::endl;
    cout << "Running weekEvents\n----------------------" << endl;
    p.weekEvents();
    cout << "\nwCount is " << p.getWeekCount() << endl;


    std::cout << std::endl;

}
