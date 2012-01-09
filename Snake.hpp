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
	SnakeOccupier(int player_number, bool head);
  	virtual TYPE get_type() { return SNAKE; }
	bool is_head();
private:
	int m_number;
	bool m_head;
};

class Snake{
public:
	Snake(int size = 3);
	int get_size();
	
private:
	int m_size;
};

#endif