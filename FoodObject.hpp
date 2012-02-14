#ifndef FOOD_OBJECT_HPP
#define FOOD_OBJECT_HPP

#include "CellObject.hpp"
#include <QPainter>
#include <QObject>
class FoodObject : public CellObject{
public:
    // Takes coords for scene.
    FoodObject(int x, int y);
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif