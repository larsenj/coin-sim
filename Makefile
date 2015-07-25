testmain: test.o GhkCo.o HashMap.o Cell.o EntityManager.o GhkGroup.o Ghk.o LineCell.o MedCell.o LdrCell.o SctCell.o LogCell.o
	g++ -std=c++0x test.o GhkCo.o HashMap.o Cell.o EntityManager.o GhkGroup.o Ghk.o LineCell.o MedCell.o LdrCell.o SctCell.o LogCell.o -o testmain

test.o: test.cpp 
	g++ -c -std=c++0x test.cpp

GhkCo.o: EnemyForces/GhkCo.cpp
	g++ -c -std=c++0x EnemyForces/GhkCo.cpp

HashMap.o: HashMap.cpp
	g++ -c -std=c++0x HashMap.cpp

Cell.o: EnemyForces/Cell.cpp
	g++ -c -std=c++0x EnemyForces/Cell.cpp

EntityManager.o: EntityManager.cpp
	g++ -c -std=c++0x EntityManager.cpp

GhkGroup.o: EnemyForces/GhkGroup.cpp
	g++ -c -std=c++0x EnemyForces/GhkGroup.cpp

Ghk.o: EnemyForces/Ghk.cpp
	g++ -c -std=c++0x EnemyForces/Ghk.cpp

LineCell.o: EnemyForces/LineCell.cpp
	g++ -c -std=c++0x EnemyForces/LineCell.cpp

MedCell.o: EnemyForces/MedCell.cpp
	g++ -c -std=c++0x EnemyForces/MedCell.cpp

LogCell.o: EnemyForces/LogCell.cpp
	g++ -c -std=c++0x EnemyForces/LogCell.cpp

LdrCell.o: EnemyForces/LdrCell.cpp
	g++ -c -std=c++0x EnemyForces/LdrCell.cpp

SctCell.o: EnemyForces/SctCell.cpp
	g++ -c -std=c++0x EnemyForces/SctCell.cpp

cells:
	g++ -c -std=c++0x EnemyForces/*Cell.cpp

clean:
	rm testmain a.out *.o  

#target: dependencies
#	system command
