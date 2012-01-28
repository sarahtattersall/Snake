#ifndef FOOD_OCCUPIER_HPP
#define FOOD_OCCUPIER_HPP
#include "CellOccupier.hpp"
class FoodOccupier : public CellOccupier{
public:
  	virtual TYPE get_type() { return FOOD; }
};

#endif
