#ifndef BOARD_BUILDER_HPP
#define BOARD_BUILDER_HPP
#include "Cell.hpp"
#include "Coord.hpp"
#include "Snake.hpp"
#include <vector>
#include <list>
#include <boost/shared_ptr.hpp>
//#include <boost/ptr_container/ptr_list.hpp>
using std::vector;
using std::list;
using boost::shared_ptr;
//using boost::ptr_list;


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
    virtual void insert(CellOccupier* occupier, Coord coord) = 0;
    // moves the occupier to the new coord and sets the occupiers previous
    // cell to empty
    virtual void move(CellOccupier* occupier, Coord coord) = 0;
    virtual void remove(CellOccupier* occupier) = 0;
    virtual Coord find(CellOccupier* occupier) = 0;
    virtual CellOccupier* lookup(Coord coord) = 0;
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
