#ifndef SCENE_HPP
#define SCENE_HPP

#include "Rules.hpp"
#include "Board.hpp"

#include <boost/shared_ptr.hpp>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QDebug>


class Scene : public QGraphicsScene{
public:
	// Hmmmm board is in rules too :S
	Scene(shared_ptr<Board> board, shared_ptr<Rules> rules);
	void keyPressEvent(QKeyEvent *event);

private:    
	QGraphicsView view;
	QPainter painter;
	shared_ptr<Board> m_board;
	shared_ptr<Rules> m_rules;
	void updateView();
	// Maps board point x to the view, taking into consideration
	// size of objects
	int mapToView(int x, int size);
};

#endif