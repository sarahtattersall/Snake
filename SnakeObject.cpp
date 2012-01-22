#include "SnakeObject.hpp"
int SnakeObject::size = 10;
SnakeObject::SnakeObject(int x, int y) : QGraphicsRectItem(x,y,size,size){	
}

void SnakeObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::green);
    painter->setPen(Qt::green);
	QGraphicsRectItem::paint(painter, option, widget);
}

int SnakeObject::get_width(){
	return size;
}

int SnakeObject::get_height(){
	return size;
}