#include "Cell.hpp"
#include "CellOccupier.hpp"

Cell::Cell(CellOccupier* occupier){
    m_occupier = occupier;
}

void Cell::set_occupier(const CellOccupier* occupier){
    m_occupier = occupier;
}

const CellOccupier* Cell::get_occupier(){
    return m_occupier;
}

bool Cell::is_occupied(){
    return m_occupier->get_type() != CellOccupier::EMPTY;
}
