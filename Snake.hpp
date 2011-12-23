#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "Coord.hpp"
#include "CellOccupier.hpp"
#include <vector>
using std::vector;

class Snake : CellOccupier{
public:
	Snake(Coord board_middle, int size = 3);
  	virtual TYPE get_type() { return SNAKE; }
private:
	int m_size;
	vector<Coord> m_coords;
};
#endif