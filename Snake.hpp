#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "Coord.hpp"
#include "CellOccupier.hpp"
#include <vector>
using std::vector;

class SnakeOccupier : public CellOccupier{
public:
	SnakeOccupier(Coord coord);
  	virtual TYPE get_type() { return SNAKE; }
};

class Snake{
public:
	Snake(Coord board_middle, int size = 3);
	// SARAH: should this return a reference? Thought not incase someone
	//  accidentally changes it.
	vector<SnakeOccupier*> get_occupiers();	
	~Snake();
private:
	int m_size;
	vector<SnakeOccupier*> m_occupiers;
};

#endif