#ifndef BOARD_BUILDER_HPP
#define BOARD_BUILDER_HPP
#include "Cell.hpp"
#include <vector>
using std::vector;


class Board{
public:
    Board(const int size);
	// Returns the cell at x, y.
	//  Done this way so that a board visulisation does
	//  not need to know how board stores it's cells.
	Cell get(int x, int y);
private:
    int m_size;
    void initialize_board();
    vector<vector<Cell> > m_cells;
    
    
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