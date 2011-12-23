#ifndef CELL_HPP
#define CELL_HPP
#include "CellOccupier.hpp"
class Coord;

class Cell{
public:
    bool is_occupied();
    void set_cell(CellOccupier* occupier);
	CellOccupier* get_occupier();
    Cell(Coord coord);
private:
    CellOccupier* m_occupier;
};

#endif