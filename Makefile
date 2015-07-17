testmain: test.o HashMap.o Cell.o EntityManager.o GhkGroup.o Ghk.o
	g++ -std=c++0x -Wall test.o HashMap.o Cell.o EntityManager.o GhkGroup.o Ghk.o -o testmain

test.o: test.cpp 
	g++ -c -std=c++0x test.cpp

HashMap.o: HashMap.cpp
	g++ -c -std=c++0x HashMap.cpp

Cell.o: Cell.cpp
	g++ -c -std=c++0x Cell.cpp

EntityManager.o: EntityManager.cpp
	g++ -c -std=c++0x EntityManager.cpp

GhkGroup.o: GhkGroup.cpp
	g++ -c -std=c++0x GhkGroup.cpp

Ghk.o: Ghk.cpp
	g++ -c -std=c++0x Ghk.cpp

cells:
	g++ -c -std=c++0x *Cell.cpp

clean:
	rm EFOrg testmain *.o 

#target: dependencies
#	system command
