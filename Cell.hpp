#ifndef CELL_HPP
#define CELL_HPP
#include "CellOccupier.hpp"
#include <Boost/shared_ptr.hpp>
using boost::shared_ptr;
class Coord;

class Cell{
public:
    bool is_occupied();
    void set_cell(shared_ptr<CellOccupier> occupier);
	shared_ptr<CellOccupier> get_occupier();
    Cell();
private:
    shared_ptr<CellOccupier> m_occupier;
};

#endif