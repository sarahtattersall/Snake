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

void Snake::push_front(Coord coord){
	m_coords.push_front(coord);
}

void Snake::push_back(Coord coord){
	m_coords.push_back(coord);
}

void Snake::remove_back(){
	m_coords.pop_back();
}

Coord Snake::back(){
	return m_coords.back();
}

Coord Snake::front(){
	return m_coords.front();
}
// vector<shared_ptr<SnakeOccupier> > Snake::get_occupiers(){
// 	return m_occupiers;
// }
