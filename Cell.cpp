#include "Cell.hpp"
#include <string.h>

Cell::Cell(){
    m_occupier = NULL;
}

void Cell::set_cell(CellOccupier* occupier){
    m_occupier = occupier;
}

bool Cell::is_occupied(){
    return m_occupier != NULL;
}