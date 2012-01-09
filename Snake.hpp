#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "Coord.hpp"
#include "CellOccupier.hpp"
#include <vector>
#include <Boost/shared_ptr.hpp>
using std::vector;
using boost::shared_ptr;

class SnakeOccupier : public CellOccupier{
public:
  	virtual TYPE get_type() { return SNAKE; }
};

class Snake{
public:
	Snake(Coord board_middle, int size = 3);
	vector<shared_ptr<SnakeOccupier> > get_occupiers();	

private:
	int m_size;
	vector<shared_ptr<SnakeOccupier> > m_occupiers;
};

#endif