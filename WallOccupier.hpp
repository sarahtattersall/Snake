#ifndef WALL_OCCUPIER_HPP
#define WALL_OCCUPIER_HPP
#include "CellOccupier.hpp"
class WallOccupier : public CellOccupier{
public:
  	virtual TYPE get_type() { return WALL; }
};

#endif
