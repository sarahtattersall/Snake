#ifndef BOARD_BUILDER_HPP
#define BOARD_BUILDER_HPP
#include "Cell.hpp"
#include "Coord.hpp"
#include <vector>
#include <list>
#include <Boost/shared_ptr.hpp>
using std::vector;
using std::list;
using boost::shared_ptr;


//IAN: Made this class a pure abstract interface
class Board {
public:
	// Returns the cell at x, y.
	//  Done this way so that a board visulisation does
	//  not need to know how board stores it's cells.
	virtual Cell& get(Coord coord) = 0;
	virtual Cell& get(int x, int y)= 0;
	virtual int get_height() = 0;
	virtual int get_width() = 0;
	virtual void insert(shared_ptr<CellOccupier> occupier, Coord coord) = 0;
	// Removes occupier in cell and sets it to empty.
	// virtual void remove(Coord coord) = 0;
protected:
	list<shared_ptr<CellOccupier> > m_snake_occupiers;
};

class BoardBuilder {
public:
    BoardBuilder();
    BoardBuilder& set_size(const int size);
    // if haven't set size create should refuse.
    shared_ptr<Board> create();
private:
    int m_size;
};


#endif
