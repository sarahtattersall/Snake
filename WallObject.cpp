#include "WallObject.hpp"
WallObject::WallObject(int x, int y) : CellObject(x,y){	
}

void WallObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::blue);
    painter->setPen(Qt::blue);
	QGraphicsRectItem::paint(painter, option, widget);
}