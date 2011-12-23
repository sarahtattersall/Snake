#include "Cell.hpp"
#include "EmptyOccupier.hpp"

Cell::Cell(Coord coord){
    m_occupier = new EmptyOccupier(coord);
}

void Cell::set_cell(CellOccupier* occupier){
    m_occupier = occupier;
}

CellOccupier* Cell::get_occupier(){
	return m_occupier;
}

bool Cell::is_occupied(){
    return m_occupier->get_type() != CellOccupier::EMPTY;
}