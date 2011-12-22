#include "Cell.hpp"
#include "EmptyOccupier.hpp"

Cell::Cell(){
    m_occupier = new EmptyOccupier();
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