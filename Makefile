testmain: test.o HashMap.o Cell.o
	g++ -std=c++0x -Wall test.o HashMap.o Cell.o -o testmain

test.o: test.cpp 
	g++ -c -std=c++0x test.cpp

HashMap.o: HashMap.cpp
	g++ -c -std=c++0x HashMap.cpp

Cell.o: Cell.cpp
	g++ -c -std=c++0x Cell.cpp

clean:
	rm EFOrg testmain *.o 

#target: dependencies
#	system command
