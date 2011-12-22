snake: main.o Board.o Cell.o
	g++ main.o Board.o Cell.o -o snake

main.o: main.cpp Board.hpp 
	g++ -c main.cpp

Board.o: Board.cpp Board.hpp Cell.hpp
	g++ -c Board.cpp 

Cell.o: Cell.cpp Cell.hpp CellOccupier.hpp
	g++ -c Cell.cpp

clean:
	rm -rf *o snake
