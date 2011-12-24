#include "Cell.hpp"
#include "EmptyOccupier.hpp"

Cell::Cell(Coord coord){
    m_occupier = shared_ptr<CellOccupier> (new EmptyOccupier(coord));
}

void Cell::set_cell(shared_ptr<CellOccupier> occupier){
    m_occupier = occupier;
}

shared_ptr<CellOccupier> Cell::get_occupier(){
	return m_occupier;
}

bool Cell::is_occupied(){
    return m_occupier->get_type() != CellOccupier::EMPTY;
}