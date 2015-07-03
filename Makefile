EFOrg: main.o GhkGroup.o Ghk.o GhkCo.o Cell.o Province.o
	g++ -std=c++0x -Wall -pthread main.o Province.o Ghk.o GhkGroup.o GhkCo.o Cell.o LineCell.o LdrCell.o LogCell.o SctCell.o MedCell.o -o EFOrg

main.o: main.cpp
	g++ -c -std=c++0x -pthread main.cpp

Ghk.o: Ghk.cpp
	g++ -c -std=c++0x Ghk.cpp

GhkGroup.o: GhkGroup.cpp
	g++ -c -std=c++0x GhkGroup.cpp

GhkCo.o: GhkCo.cpp
	g++ -c -std=c++0x GhkCo.cpp

Cell.o: Cell.cpp
	g++ -c -std=c++0x Cell.cpp

Province.o: Province.cpp
	g++ -c -std=c++0x Province.cpp

testmain:
	g++ -std=c++0x -Wall test.o Province.o Ghk.o GhkGroup.o GhkCo.o Cell.o LineCell.o LdrCell.o LogCell.o SctCell.o MedCell.o -o testmain

test.o: test.cpp
	g++ -c -std=c++0x test.cpp

cells:
	g++ -c -std=c++0x *Cell.cpp 

clean:
	rm EFOrg testmain *.o 

#target: dependencies
#	system command
