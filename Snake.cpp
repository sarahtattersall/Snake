#include "Snake.hpp"

Snake::Snake(Coord board_middle, int size) {
	m_size = size;
	int x = board_middle.get_x();
	int y = board_middle.get_y();
	for( int i = 0; i < size; ++i){
		m_occupiers.push_back(new SnakeOccupier(Coord(x, y--)));
	}
}

Snake::~Snake(){
	// for( vector<SnakeOccupier*>::iterator itr = m_occupiers.begin(); itr != m_occupiers.end(); ++itr){
	// 	delete *itr;
	// }
}

vector<SnakeOccupier*> Snake::get_occupiers(){
	return m_occupiers;
}

SnakeOccupier::SnakeOccupier(Coord coord) : CellOccupier(coord){
}

