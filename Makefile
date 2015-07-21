testmain: test.o GhkCo.o HashMap.o Cell.o EntityManager.o GhkGroup.o Ghk.o LineCell.o MedCell.o LdrCell.o SctCell.o LogCell.o
	g++ -std=c++0x test.o GhkCo.o HashMap.o Cell.o EntityManager.o GhkGroup.o Ghk.o LineCell.o MedCell.o LdrCell.o SctCell.o LogCell.o -o testmain

test.o: test.cpp 
	g++ -c -std=c++0x test.cpp

GhkCo.o: GhkCo.cpp
	g++ -c -std=c++0x GhkCo.cpp

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

LineCell.o: LineCell.cpp
	g++ -c -std=c++0x LineCell.cpp

MedCell.o: MedCell.cpp
	g++ -c -std=c++0x MedCell.cpp

LogCell.o: LogCell.cpp
	g++ -c -std=c++0x LogCell.cpp

LdrCell.o: LdrCell.cpp
	g++ -c -std=c++0x LdrCell.cpp

SctCell.o: SctCell.cpp
	g++ -c -std=c++0x SctCell.cpp

cells:
	g++ -c -std=c++0x *Cell.cpp

clean:
	rm EFOrg testmain a.out *.o 

#target: dependencies
#	system command
