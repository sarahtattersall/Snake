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

FoodObject::FoodObject(int x, int y) : CellObject(x,y){	
}

void FoodObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::yellow);
    painter->setPen(Qt::yellow);
	QGraphicsRectItem::paint(painter, option, widget);
}

SnakeObject::SnakeObject(int x, int y) : CellObject(x,y){   
}

void SnakeObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::green);
    painter->setPen(Qt::green);
    QGraphicsRectItem::paint(painter, option, widget);
}

SnakeDeadObject::SnakeDeadObject(int x, int y) : CellObject(x,y){   
}

void SnakeDeadObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::red);
    painter->setPen(Qt::red);
    QGraphicsRectItem::paint(painter, option, widget);
}

WallObject::WallObject(int x, int y) : CellObject(x,y){ 
}

void WallObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    QGraphicsRectItem::paint(painter, option, widget);
}