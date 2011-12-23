snake: main.o Board.o Cell.o BoardVisualiser.o CellOccupier.o EmptyOccupier.o TextualBoardVisualiser.o Snake.o Rules.o Coord.o
	g++ main.o Board.o Cell.o BoardVisualiser.o CellOccupier.o EmptyOccupier.o TextualBoardVisualiser.o Snake.o Rules.o Coord.o -o snake

main.o: main.cpp Board.hpp BoardVisualiser.hpp
	g++ -c main.cpp

Board.o: Board.cpp Board.hpp Cell.hpp Coord.hpp
	g++ -c Board.cpp 

Cell.o: Cell.cpp Cell.hpp CellOccupier.hpp
	g++ -c Cell.cpp

BoardVisualiser.o: BoardVisualiser.cpp BoardVisualiser.hpp Board.hpp
	g++ -c BoardVisualiser.cpp

CellOccupier.o: CellOccupier.cpp CellOccupier.hpp
	g++ -c CellOccupier.cpp

EmptyOccupier.o: EmptyOccupier.cpp EmptyOccupier.hpp CellOccupier.hpp
	g++ -c EmptyOccupier.cpp

TextualBoardVisualiser.o: TextualBoardVisualiser.cpp TextualBoardVisualiser.hpp BoardVisualiser.hpp
	g++ -c TextualBoardVisualiser.cpp

Snake.o: Snake.cpp Snake.hpp Coord.hpp
	g++ -c Snake.cpp

Rules.o: Rules.cpp Rules.hpp Snake.hpp Board.hpp
	g++ -c Rules.cpp

Coord.o: Coord.cpp Coord.hpp

clean:
	rm -rf *o snake
