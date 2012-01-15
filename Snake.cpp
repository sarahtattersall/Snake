#include "Snake.hpp"
#include <iostream>

SnakeOccupier::SnakeOccupier(int player_number, bool head) : CellOccupier(){
	m_number = player_number;
	m_head = head;
}

bool SnakeOccupier::is_head(){
	return m_head;
}

Snake::Snake(int size) {
	m_size = size;
}

int Snake::get_size(){
	return m_size;
}

void Snake::add_front(Coord coord){
	m_coords.push_front(coord);
}

void Snake::add_back(Coord coord){
	m_coords.push_back(coord);
}
// vector<shared_ptr<SnakeOccupier> > Snake::get_occupiers(){
// 	return m_occupiers;
// }
