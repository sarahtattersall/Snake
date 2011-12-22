#include "CellOccupier.hpp"
CellOccupier::CellOccupier(TYPE type){
	m_type = type;
}

CellOccupier::TYPE CellOccupier::get_type(){
	return m_type;
}