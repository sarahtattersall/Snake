#include "CellOccupier.hpp"

// SARAH: Should I have made m_coord a pointer? But it's so small?
CellOccupier::CellOccupier(Coord coord) : m_coord(coord.get_x(), coord.get_y()){
}

Coord CellOccupier::get_coord(){
	return m_coord;
}