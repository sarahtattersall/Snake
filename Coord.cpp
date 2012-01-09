#include "Coord.hpp"
Coord::Coord(int x, int y){
	m_x = x;
	m_y = y;
}

int Coord::get_x(){
	return m_x;
}

int Coord::get_y(){
	return m_y;
}

Coord Coord::operator+(const Coord& coord) const{
	Coord result(m_x + coord.m_x, m_y + coord.m_y);
    return result;
}

Coord Coord::operator-(const Coord& coord) const{
	Coord result(m_x + coord.m_x, m_y + coord.m_y);
    return result;
}

Coord Coord::operator=(const Coord& coord){
	m_x = coord.m_x;
	m_y = coord.m_y;
    return *this;
}