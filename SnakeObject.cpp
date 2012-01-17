#include "SnakeObject.hpp"
SnakeObject::SnakeObject(int x, int y) : QGraphicsRectItem(x,y,10,10){	
}

void SnakeObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::green);
    painter->setPen(Qt::green);
	QGraphicsRectItem::paint(painter, option, widget);
}