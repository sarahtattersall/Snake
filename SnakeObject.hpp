#ifndef SNAKE_OBJECT_HPP
#define SNAKE_OBJECT_HPP

#include <QGraphicsRectItem>
#include <QPainter>
#include <QObject>
class SnakeObject : public QGraphicsRectItem{
private:
	static int size;
public:
	// Takes coords for scene.
	SnakeObject(int x, int y);
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	static int get_width();
	static int get_height();
};

#endif