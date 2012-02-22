#ifndef CELL_HPP
#define CELL_HPP
#include "CellOccupier.hpp"
class Coord;

class Cell{
public:
    bool is_occupied();
    void set_occupier(const CellOccupier* occupier);
    const CellOccupier* get_occupier();
    Cell(CellOccupier* occupier);
private:
    const CellOccupier* m_occupier;
};

#endif
