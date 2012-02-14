#ifndef EMPTY_OCCUPIER_HPP
#define EMPTY_OCCUPIER_HPP
#include "CellOccupier.hpp"
class EmptyOccupier : public CellOccupier{
public:
    virtual TYPE get_type() { return EMPTY; }
};

#endif
