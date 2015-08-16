#include "EFWrapper.h"
#include <iostream>
#include <cstddef>
#include <memory>
#include <string>
#include "HashMap.h"
#include "EntityManager.h"
#include "CommoNet.h"
#include "Province.h"
#include <vector>

using namespace std;

int main() {

    std::cout << "\nTesting Province" << std::endl;
    Province p("Oz", 1, 2, 50);
    std::cout << p.getName() << "'s ID is " << p.getID() << std::endl;
    cout << "Running weekEvents\n----------------------" << endl;
    p.weekEvents();
    cout << "\nwCount is " << p.getWeekCount() << endl;


    (p.getStability() == 50) ? cout << "getStab success" << endl :
        cout << "getStab FAIL" << endl;
    
    bool testUp = true;
    p.upStability(5);
    if (p.getStability() != 55) testUp = false;
    p.upStability(1000);
    if (p.getStability() != 100) testUp = false;

    bool testDown = true;
    p.downStability(5);
    if (p.getStability() != 95) testDown = false;
    p.downStability(1000);
    if (p.getStability() != 0) testDown = false;

    (testUp) ? cout << "upStab success" << endl :
        cout << "upStab FAIL" << endl;
    (testDown) ? cout << "downStab success" << endl :
        cout << "downStab FAIL" << endl;


}
/*  
 
GhkGroup f(17020000, 1);
f.dayEvents();
f.dayEvents();
f.dayEvents();
std::cout << std::endl;
 
   
bool cellgen = true;
LineCell* x = NULL;
x = new LineCell(100,1);
vector<Cell*> v;
v.push_back(x);
if(x->hasLeader() != v[0]->hasLeader())
    cellgen = false;
MedCell* y(new MedCell(101, 1));
v.push_back(y);
if(y->getID() != v[1]->getID())
    cellgen = false;

delete x;
x = NULL;
delete y;
y = NULL;


//HashMap tests
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
    if (a->getID() != cell->getID()) cout << "getObj fail" << endl;
    else cout << "getObj success" << endl;
    int remove = h.removeItem(a->getID());
    int fail = h.removeItem(1);
    if (remove != 0 && fail != 1) cout << "removeItem fail" << endl;
    else cout << "removeItem success" << endl;
    a = h.getObj(cell->getID());
    if (a == NULL)
        cout << "get removed success" << endl;
    else
        cout << "get removed failed" << endl;
    h.addItem(cell->getID(), cell);
    if (h.numItemsInIndex(13) != 1 && h.numItemsInIndex(14) != 0) cout << 
        "numItemsInIndex fail" << endl;
    else cout << "numItemsInIndex success" << endl;
    cout << "Adding more cells";
    Cell* cell2 = new Cell(17000006);
    h.addItem(cell2->getID(), cell2);
    Cell* cell3 = new Cell(17000007);
    h.addItem(cell3->getID(), cell3);
    Cell* cell4 = new Cell(17000104);
    h.addItem(cell4->getID(), cell4);
    cout << " and listing all" << endl;
    h.listAll();
    a = h.getObj(17000104);
    if (a->getID() == 17000104)
        cout << "\nlinked list works" << endl;
    else

//EntityManager Tests
    EntityMgr->RegisterEntity(cell);
    EntityMgr->RegisterEntity(cell2);
    EntityMgr->RegisterEntity(cell3);
    Cell* cell5 = EntityMgr->GetEntityFromID(cell2->getID());
    bool getEnt = true;//test GetEntityFromID
    if (cell5->getID() != cell2->getID()) getEnt = false;
    EntityMgr->RemoveEntity(cell2);
    cell5 = EntityMgr->GetEntityFromID(cell2->getID());
    if (cell5 == NULL) cout << "remove entity success" << endl;
    else cout << "remove entity fail" << endl;
    EntityMgr->RemoveAll();
*/
/*    //cleanup
    delete cell;
    cell = nullptr;
    delete cell2;
    cell2 = nullptr;
    delete cell3;
    cell3 = nullptr;
    delete cell4;
    cell4 = nullptr;
*/

/*    
//testing vector of pointers, adding to EM
    bool ghkgrp = true;
    GhkGroup g(17010000, 1);
    if (g.getID() != 17010100){
        //cout << "GhkGroup creation fail" << endl;
        ghkgrp = false;
    }
    for (int i = 0; i < 1; i++)
        if (g.getCellID(i) != g.getID()+i+1){
            //cout << "Cell creation fail" << endl;
            ghkgrp = false;
        }
    cout << "Day events" << endl;
    g.dayEvents();
    g.~GhkGroup();

    unique_ptr<GhkCo> c(new GhkCo(17000000, 1));
    EntityMgr->ListAll();

    LineCell* LC = new LineCell(1, 10);
    bool lineCreation = true;
    if (LC->getSupplies() != 100) lineCreation = false;
    v.push_back(LC);
    if (v.back()->getSupplies() != 100)lineCreation = false;
    v.emplace_back(new LineCell(8, 10));
//    cout << "LineCell address =  " << v[1] << endl;
//    cout << "Pointer address =  " << &v[1] << endl;
 //   cout << "[0] pointer address =  " << &v[0] << endl;
    


    (getEnt) ? cout << "Get entity success" << endl :
        cout << "Get entity fail" << endl;
    (cellgen)?cout << "Cellgen success" << endl : cout << "Cellgen fail" << endl;
    (ghkgrp) ? cout << "GhkGroup creation success" << endl :
        cout << "GhkGroup creation fail" << endl;
    (lineCreation)? cout << "LineCell supplies success" << endl : cout << "LineCell supplies fail" << endl;
*/
    //Create hierarchy and add to EM tests
    //GhkGroup gg(17010000, 1);


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

