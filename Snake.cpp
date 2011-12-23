#include "Snake.hpp"

Snake::Snake(Coord board_middle, int size) : CellOccupier(){
	m_size = size;
	int x = board_middle.get_x();
	int y = board_middle.get_y();
	for( int i = 0; i < size; ++i){
		m_coords.push_back(Coord(x, y--));
	}
}