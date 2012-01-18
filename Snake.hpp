#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "Coord.hpp"
#include "CellOccupier.hpp"
#include <deque>
#include <Boost/shared_ptr.hpp>
using std::deque;
using boost::shared_ptr;

class SnakeOccupier : public CellOccupier{
public:
	SnakeOccupier();
  	virtual TYPE get_type() { return SNAKE; }
};


// TODO: SNAKE DOESNT NEED TO HOLD COORDINATES JUST MAKE SNAKE OCCUPIERS
// IN BOARD A LINKED LIST, MOVE THE HEAD AND REINSERT TAIL NEXT TO HEAD.
// TRY AND MAKE IT CIRCULAR
class Snake{
public:
	Snake(int size = 3);
	int get_size();
	// Adds coord at head of snake
	void push_front(Coord coord);
	// Adds coord at back of snake
	void push_back(Coord coord);
	void remove_back();
	Coord back();
	Coord front();
	
private:
	int m_size;
	deque<Coord> m_coords;
};

#endif