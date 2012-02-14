#include "Cell.hpp"
#include "EmptyOccupier.hpp"

Cell::Cell(CellOccupier* occupier){
    m_occupier = occupier;
}

void Cell::set_occupier(CellOccupier* occupier){
    m_occupier = occupier;
}

CellOccupier* Cell::get_occupier(){
    return m_occupier;
}

bool Cell::is_occupied(){
    return m_occupier->get_type() != CellOccupier::EMPTY;
}
