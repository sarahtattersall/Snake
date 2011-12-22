snake: main.o Board.o Cell.o BoardVisualiser.o CellOccupier.o EmptyOccupier.o
	g++ main.o Board.o Cell.o BoardVisualiser.o CellOccupier.o EmptyOccupier.o -o snake

main.o: main.cpp Board.hpp BoardVisualiser.hpp
	g++ -c main.cpp

Board.o: Board.cpp Board.hpp Cell.hpp
	g++ -c Board.cpp 

Cell.o: Cell.cpp Cell.hpp CellOccupier.hpp
	g++ -c Cell.cpp

BoardVisualiser.o: BoardVisualiser.cpp BoardVisualiser.hpp Board.hpp
	g++ -c BoardVisualiser.cpp

CellOccupier.o: CellOccupier.cpp CellOccupier.hpp
	g++ -c CellOccupier.cpp

EmptyOccupier.o: EmptyOccupier.cpp EmptyOccupier.hpp CellOccupier.hpp
	g++ -c EmptyOccupier.cpp

clean:
	rm -rf *o snake
