#include "FoodObject.hpp"
FoodObject::FoodObject(int x, int y) : CellObject(x,y){	
}

void FoodObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::yellow);
    painter->setPen(Qt::yellow);
	QGraphicsRectItem::paint(painter, option, widget);
}