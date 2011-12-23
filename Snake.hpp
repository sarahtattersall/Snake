#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "CellOccupier.hpp"
class Snake : CellOccupier{
public:
  virtual TYPE get_type() { return SNAKE; }
};

#endif