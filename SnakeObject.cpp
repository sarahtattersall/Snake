#include "SnakeObject.hpp"
SnakeObject::SnakeObject(int x, int y) : CellObject(x,y){	
}

void SnakeObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::green);
    painter->setPen(Qt::green);
	QGraphicsRectItem::paint(painter, option, widget);
}