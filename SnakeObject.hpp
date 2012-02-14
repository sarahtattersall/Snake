#ifndef SNAKE_OBJECT_HPP
#define SNAKE_OBJECT_HPP

#include "CellObject.hpp"
#include <QPainter>
#include <QObject>
class SnakeObject : public CellObject{
public:
	// Takes coords for scene.
	SnakeObject(int x, int y);
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

class SnakeDeadObject : public CellObject{
public:
	SnakeObject(int x, int y);
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif