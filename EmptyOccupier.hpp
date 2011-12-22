#ifndef EMPTY_OCCUPIER_HPP
#define EMPTY_OCCUPIER_HPP
#include "CellOccupier.hpp"

class EmptyOccupier : public CellOccupier{
public:
  //IAN: Return the type directly rather than from a field.
  // see CellOccupier for more comments about this.
  virtual TYPE get_type() { return EMPTY; }
};

#endif
