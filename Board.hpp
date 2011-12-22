#ifndef BOARD_BUILDER_HPP
#define BOARD_BUILDER_HPP
#include "Cell.hpp"
#include <vecto>r
using std::vector;


//IAN: Made this class a pure abstract interface
class Board {
public:
	// Returns the cell at x, y.
	//  Done this way so that a board visulisation does
	//  not need to know how board stores it's cells.
  //IAN: Have to return cell by reference if you want to be able to modify it.
	virtual Cell& get(int x, int y) = 0;
	virtual int get_height() = 0;
	virtual int get_width() = 0;
};

class BoardBuilder {
public:
    BoardBuilder();
    BoardBuilder& set_size(const int size);
    // if haven't set size create should refuse.
    Board* create();
private:
    int m_size;
};


#endif
