#include "CellOccupier.hpp"

CellOccupier::CellOccupier(Coord coord) : m_coord(coord){
}

Coord CellOccupier::get_coord(){
	return m_coord;
}