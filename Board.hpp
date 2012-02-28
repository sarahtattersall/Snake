#ifndef BOARD_BUILDER_HPP
#define BOARD_BUILDER_HPP
#include "CellOccupier.hpp"
#include "Coord.hpp"
#include <vector>
#include <list>
#include <boost/shared_ptr.hpp>
using boost::shared_ptr;
using std::vector;

//IAN: Made this class a pure abstract interface
class Board {
public:
    virtual int get_height() = 0;
    virtual int get_width() = 0;
    virtual void insert(CellOccupier* occupier, Coord coord) = 0;
    // Moves the occupier to the new coord and sets the occupiers previous
    // cell to empty
    virtual void move(const CellOccupier* occupier, Coord coord) = 0;
    // Removes the cell occupier from the board
    virtual void remove(const CellOccupier* occupier) = 0;
    // Finds the coordinate of the cell occupier
    virtual Coord find(const CellOccupier* occupier) = 0;
    // Finds all coordinates a cell occupier is 
    virtual vector<Coord> find_all(const CellOccupier* occupier) = 0;
    virtual const CellOccupier* lookup(Coord coord) = 0;
    // Clears the contents of the board.
    virtual void clear() = 0;
};

class BoardBuilder {
public:
    BoardBuilder();
    BoardBuilder& set_size(const int size);
    // If haven't set size create will error.
    shared_ptr<Board> create();
private:
    int m_size;
};


#endif
