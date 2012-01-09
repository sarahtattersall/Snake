#include "Snake.hpp"
#include <iostream>

SnakeOccupier::SnakeOccupier(int player_number) : CellOccupier(){
	m_number = player_number;
}

Snake::Snake(int size) {
	m_size = size;
}

int Snake::get_size(){
	return m_size;
}
// vector<shared_ptr<SnakeOccupier> > Snake::get_occupiers(){
// 	return m_occupiers;
// }
