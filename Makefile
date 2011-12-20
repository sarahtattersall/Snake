snake: main.o Board.o
	g++ main.o Board.o -o snake

main.o: main.cpp Board.hpp 
	g++ -c main.cpp

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp 

clean:
	rm -rf *o snake
