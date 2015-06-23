
ThreadCells: main.o Province.o Cells.o 
	g++ -std=c++0x -pthread main.o Province.o Cells.o -o ThreadCells

main.o: main.cpp
	g++ -c -std=c++0x -pthread main.cpp

Province.o: Province.cpp
	g++ -c -std=c++0x Province.cpp

Cells.o: Cells.cpp
	g++ -c Cells.cpp

clean:
	rm ThreadCells a.out *.o

test:
	g++ -std=c++0x test.o Cells.o LineCell.o -o testmain

test.o:
	g++ -c -std=c++0x test.cpp

LineCell.o:
	g++ -c -std=c++0x LineCell.cpp

build:
	g++ -c -std=c++0x *.cpp *.h

#target: dependencies
#	system command
