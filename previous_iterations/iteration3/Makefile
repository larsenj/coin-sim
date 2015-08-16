CC = g++
CFLAGS = -std=c++0x -pthread 
OBJECTS = main.o Province.o GhkCo.o HashMap.o Cell.o EntityManager.o GhkGroup.o Ghk.o CommoNet.o LineCell.o MedCell.o LdrCell.o SctCell.o LogCell.o 

#OBJECTS = test.o Province.o GhkCo.o HashMap.o Cell.o EntityManager.o GhkGroup.o Ghk.o CommoNet.o LineCell.o MedCell.o LdrCell.o SctCell.o LogCell.o 

Coin: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o Coin

#testmain: $(OBJECTS)
#	$(CC) $(CFLAGS) $(OBJECTS) -o testmain

#test.o: test.cpp
#	$(CC) $(CFLAGS) -c test.cpp

%.o: EnemyForces/%.cpp
	$(CC) $(CFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm Coin testmain a.out *.o  

#target: dependencies
#	system command
