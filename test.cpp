#include "CellWrapper.h"
#include <iostream>
#include <cstddef>
#include <string>
#include "HashMap.h"

using namespace std;

int main() {

    HashMap<Cell> h;
    //100000000
    Cell* cell = new Cell(17000005);
    h.addItem(cell->getID(), cell);
    cout << "Cell id = " << cell->getID();
    cout << "\tHash = " << h.hash(cell->getID()) << endl; 
    cout << "hash of 17000001 = " << h.hash(17000001) << endl;   
    cout << "hash of 17200007 = " << h.hash(17200007) << endl;   
    cout << "hash of 17200008 = " << h.hash(17200008) << endl;   
    cout << "hash of 17200009 = " << h.hash(17200009) << endl;   
    cout << "hash of 17200010 = " << h.hash(17200010) << endl;   
    Cell* a = h.getObj(cell->getID());
    cout << "a id is " << a->getID() << endl;
    int remove = h.removeItem(a->getID());
    cout << "int is " << remove << endl;
    int fail = h.removeItem(1);
    cout << "fail is " << fail << endl;
    a = h.getObj(cell->getID());
    if (a == NULL)
        cout << "remove worked" << endl;
    else
        cout << "remove failed" << endl;
    cout << "Adding the cell back in" << endl;
    h.addItem(cell->getID(), cell);
    cout << "Items in bucket 13 = " << h.numItemsInIndex(13) << endl;
    cout << "Items in bucket 14 = " << h.numItemsInIndex(14) << endl;
    cout << "Adding more cells" << endl;
    Cell* cell2 = new Cell(17000006);
    h.addItem(cell2->getID(), cell2);
    Cell* cell3 = new Cell(17000007);
    h.addItem(cell3->getID(), cell3);
    Cell* cell4 = new Cell(17000104);
    h.addItem(cell4->getID(), cell4);
    cout << "Listing all" << endl;
    h.listAll();
/*    std::cout << "\nTesting line cell:" << std::endl;
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
*/

    std::cout << std::endl;

}
