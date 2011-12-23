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