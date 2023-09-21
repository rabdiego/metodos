ALL: main

main: main.o RootSolver.o Function.o
	g++ main.o RootSolver.o Function.o -o main

main.o: main.cpp RootSolver.cpp RootSolver.h exprtk.hpp
	g++ -c main.cpp

RootSolver.o: RootSolver.cpp RootSolver.h Function.cpp Function.h
	g++ -c RootSolver.cpp

Function.o: Function.cpp Function.h exprtk.hpp
	g++ -c Function.cpp

clean:
	rm -f *.o main