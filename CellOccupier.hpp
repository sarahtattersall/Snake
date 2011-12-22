#ifndef CELL_OCCUPIER_HPP
#define CELL_OCCUPIER_HPP

class CellOccupier{
public:
	enum TYPE {EMPTY, SNAKE, FOOD};
	CellOccupier(TYPE type);
	TYPE get_type();
protected:
	TYPE m_type;    
};

#endif