snake: main.o Board.o Cell.o CellOccupier.o EmptyOccupier.o BoardVisualiser.o TextualBoardVisualiser.o Snake.o Rules.o Coord.o
	g++ main.o Board.o Cell.o CellOccupier.o EmptyOccupier.o BoardVisualiser.o TextualBoardVisualiser.o Snake.o Rules.o Coord.o -o snake

test: test.o BoardTest.o RulesTest.o Board.o Cell.o CellOccupier.o EmptyOccupier.o BoardVisualiser.o TextualBoardVisualiser.o Snake.o Rules.o Coord.o
	g++ test.o BoardTest.o RulesTest.o Board.o Cell.o CellOccupier.o EmptyOccupier.o BoardVisualiser.o TextualBoardVisualiser.o Snake.o Rules.o Coord.o -o test -lcppunit

test.o: test.cpp
	g++ -c test.cpp

BoardTest.o: BoardTest.cpp BoardTest.hpp Board.hpp
	g++ -c BoardTest.cpp

RulesTest.o: RulesTest.cpp RulesTest.hpp Rules.hpp
	g++ -c RulesTest.cpp

main.o: main.cpp Rules.hpp TextualBoardVisualiser.hpp SnakeException.hpp
	g++ -c main.cpp

Board.o: Board.cpp Board.hpp Cell.hpp Coord.hpp SnakeException.hpp
	g++ -c Board.cpp 

Cell.o: Cell.cpp Cell.hpp CellOccupier.hpp
	g++ -c Cell.cpp

CellOccupier.o: CellOccupier.cpp CellOccupier.hpp
	g++ -c CellOccupier.cpp

EmptyOccupier.o: EmptyOccupier.cpp EmptyOccupier.hpp CellOccupier.hpp
	g++ -c EmptyOccupier.cpp

BoardVisualiser.o: BoardVisualiser.cpp BoardVisualiser.hpp
	g++ -c BoardVisualiser.cpp

TextualBoardVisualiser.o: TextualBoardVisualiser.cpp TextualBoardVisualiser.hpp BoardVisualiser.hpp SnakeException.hpp
	g++ -c TextualBoardVisualiser.cpp

Snake.o: Snake.cpp Snake.hpp Coord.hpp
	g++ -c Snake.cpp

Rules.o: Rules.cpp Rules.hpp Snake.hpp Board.hpp Coord.hpp SnakeException.hpp
	g++ -c Rules.cpp

Coord.o: Coord.cpp Coord.hpp
	g++ -c Coord.cpp
clean:
	rm -rf *o snake
