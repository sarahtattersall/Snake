#ifndef WALL_OCCUPIER_HPP
#define WALL_OCCUPIER_HPP

class WallOccupier : public CellOccupier{
public:
  	virtual TYPE get_type() { return WALL; }
};

#endif
