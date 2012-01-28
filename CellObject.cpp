#include "CellObject.hpp"
int CellObject::s_size = 10;
CellObject::CellObject(int x, int y) : QGraphicsRectItem(x,y,s_size,s_size){	
}


int CellObject::get_width(){
	return s_size;
}

int CellObject::get_height(){
	return s_size;
}