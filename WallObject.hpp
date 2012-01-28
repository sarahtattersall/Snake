#ifndef WALL_OBJECT_HPP
#define WALL_OBJECT_HPP

#include "CellObject.hpp"
#include <QPainter>
#include <QObject>
class WallObject : public CellObject{
public:
	// Takes coords for scene.
	WallObject(int x, int y);
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif