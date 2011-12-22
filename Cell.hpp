#ifndef CELL_HPP
#define CELL_HPP
#include "CellOccupier.hpp"

class Cell{
public:
    bool is_occupied();
    void set_cell(CellOccupier* occupier);
    Cell();
private:
    CellOccupier* m_occupier;
};

#endif