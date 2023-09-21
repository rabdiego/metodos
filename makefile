ALL: main

main: exprtk_main.o Function.o
	g++ exprtk_main.o Function.o -o main

exprtk_main.o: exprtk_main.cpp Function.h exprtk.hpp
	g++ -c exprtk_main.cpp

Function.o: Function.cpp Function.h exprtk.hpp
	g++ -c Function.cpp

clean:
	rm -f *.o main